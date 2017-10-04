#include<cstdlib>
#include<cstring>
using namespace std;

int main(int ac, char** av) {
	char bf[30] = "image.x ";
	for(int i=1; i<ac; i++) {
		strcpy(bf + 8, av[i]);
		strcat(bf, "&");
		system(bf);
	}
}

