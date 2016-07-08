#include<mgl2/glut.h>
#include<cmath>
/*int sample(mglGraph *gr)
{
	gr->Rotate(60,40);
	gr->Box();
	return 0;
}
*/
void mgls_prepare2d(mglData *a, mglData *b=0, mglData *v=0)
{
  register long i,j,n=50,m=40,i0;
  if(a) a->Create(n,m);   if(b) b->Create(n,m);
  if(v) { v->Create(9); v->Fill(-1,1);  }
  mreal x,y;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)
  {
    x = i/(n-1.); y = j/(m-1.); i0 = i+n*j;
    if(a) a->a[i0] = 0.6*sin(2*M_PI*x)*sin(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
    if(b) b->a[i0] = 0.6*cos(2*M_PI*x)*cos(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
  }
}
void mgls_prepare1d(mglData *y, mglData *y1=0, mglData *y2=0, mglData *x1=0, mglData *x2=0)
{
  register long i,n=50;
  if(y) y->Create(n,3);
  if(x1)  x1->Create(n);    if(x2)  x2->Create(n);
  if(y1)  y1->Create(n);    if(y2)  y2->Create(n);
  mreal xx;
  for(i=0;i<n;i++)
  {
    xx = i/(n-1.);
    if(y)
    {
      y->a[i] = 0.7*sin(2*M_PI*xx) + 0.5*cos(3*M_PI*xx) + 0.2*sin(M_PI*xx);
      y->a[i+n] = sin(2*M_PI*xx);
      y->a[i+2*n] = cos(2*M_PI*xx);
    }
    if(y1)  y1->a[i] = 0.5+0.3*cos(2*M_PI*xx);
    if(y2)  y2->a[i] = 0.3*sin(2*M_PI*xx);
    if(x1)  x1->a[i] = xx*2-1;
    if(x2)  x2->a[i] = 0.05+0.03*cos(2*M_PI*xx);
  }
}
int sample(mglGraph *gr)
{
  mglData y;  mgls_prepare1d(&y); gr->SetOrigin(0,0,0);
  gr->SubPlot(2,2,0,"");  gr->Title("Plot plot (default)");
  gr->Box();  gr->Plot(y);

  gr->SubPlot(2,2,2,"");  gr->Title("'!' style; 'rgb' palette");
  gr->Box();  gr->Plot(y,"o!rgb");

  gr->SubPlot(2,2,3,"");  gr->Title("just markers");
  gr->Box();  gr->Plot(y," +");

  gr->SubPlot(2,2,1); gr->Title("3d variant");
  gr->Rotate(50,60);  gr->Box();
  mglData yc(30), xc(30), z(30);  z.Modify("2*x-1");
  yc.Modify("sin(pi*(2*x-1))"); xc.Modify("cos(pi*2*x-pi)");
  gr->Plot(xc,yc,z,"rs");
  return 0;
}

int main(int argc, char** argv)
{
	//mglGraph gr;
	//gr.FPlot("sin(pi*x)");
	//gr.FPlot("x*x");
	//gr.WriteFrame("test.png");
	mglGLUT gr2(sample, "MathGL examples");
	return gr2.Run();
}
