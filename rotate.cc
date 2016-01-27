#include <gdkmm/pixbuf.h>
#include <gtkmm/application.h>
#include <complex>
#include <iostream>
#include <string>
#include <cmath>//M_PI
using namespace std;

void rotate(float& x, float& y, float rad)
{
	complex<float> a {x, y};
	a *= complex<float> {cos(rad), sin(rad)};
	x = a.real();
	y = a.imag();
}
void get_new_dimension(int& w, int& h, float rad)
{
	float fw1 = w /2;
	float fh1 = h /2;
	rotate(fw1, fh1, rad);
	float fw2 = w/2;
	float fh2 = -h/2;
	rotate(fw2, fh2, rad);
	fw1 = abs(fw1) * 2;
	fh1 = abs(fh1) * 2;
	fw2 = abs(fw2) * 2;
	fh2 = abs(fh2) * 2;
	w = fw1 > fw2 ? fw1 : fw2;
	h = fh1 > fh2 ? fh1 : fh2;
}

int main(int argc, char *argv[]) 
{
	if(argc < 4) {
		cout << "usage : rotate [source file] [degree] [dest file]" << endl;
		cout << "degree will be multiplied by PI." << endl;
		cout << "example : rotate a.png 0.25 b.jpeg" << endl;
		cout << "          will rotate a.png 1/4 * PI and write to b.jpeg" << endl;
		cout << "only png, bmp, jpeg file extension is possible" << endl;
	} else {
		auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
		auto pb = Gdk::Pixbuf::create_from_file(argv[1]);
		int w = pb->get_width();
		int h = pb->get_height();
		auto a = pb->get_has_alpha();
		auto b = pb->get_bits_per_sample();
		auto c = pb->get_colorspace();
		auto r = pb->get_rowstride();
		auto n = pb->get_n_channels();
		auto p = pb->get_pixels();

		int qw = w;
		int qh = h;
		float rad = stof(argv[2]) * M_PI;
		get_new_dimension(qw, qh, rad);
		auto q = Gdk::Pixbuf::create(c, a, b, qw, qh);
		q->fill(0);
		auto rq = q->get_rowstride();
		auto nq = q->get_n_channels();
		auto pq = q->get_pixels();

		auto fp = [=] (int x, int y) {return p + y * r + x * n;};
		auto fq = [=] (int x, int y) {return pq + y * rq + x * nq;};

		unsigned char *pp, *qq;
		float xx, yy;
		for(int x = 0; x < qw; x++) {
			for(int y = 0; y < qh; y++) {
				xx = x + 0.5;
				yy = y + 0.5;
				yy = qh - yy;
				xx -= qw/2;
				yy -= qh/2;
				rotate(xx, yy, -rad);
				xx += w/2 ;
				yy += h/2;
				yy = h - yy;
				if(xx < w && xx >=0 && yy < h && yy >=0) {
					qq = fq(x, y);
					pp = fp(xx, yy);
					for(int i=0; i<4; i++) qq[i] = pp[i];
				}
			}
		}
		string s = string(argv[3]);
		s = s.substr(s.find_last_of(".") + 1);
		q->save(argv[3], s); //jpeg, bmp, png, ico possible	
		return 0;
	}
}
