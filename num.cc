#include <iostream>

bool isupdown(int i) {
	short s[10];
	int k=0;
	for(int j=1; j<i; j *= 10) s[k++] = (i/j)%10;

	bool up=false, down=false;
	for(int j=0; j<k-1; j++) {
		if(s[j] < s[j+1]) up = true;
		else if(s[j] > s[j+1]) down = true;
	}
	return up && down;
}

int main()
{
	for(float i=1, k=0, f = 0; f<0.95; i++) {
		if(isupdown(i)) k++;
		f = k/i;
		std::cout << i << " " << k << " : "  << f << std::endl;
	}
}
