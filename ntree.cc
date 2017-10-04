#include<iostream>

int nTree(int n)
{
	if(n <= 1) return 1;
	int sum = 0;
	for(int m=0; m<n; m++) sum +=  nTree(m) * nTree(n - m - 1);
	return sum;
}
int nt(int n)
{
	static int i = 0;
	static int c = 0;
	if(i == n) {
		i--;
		c++;
		return 0;
	}
	i++;
	nt(n);
	i++;
	nt(n);
	i--;
	return c;
}


int main(int c, char** v)
{
	std::cout << nt(atoi(v[1]));

}

