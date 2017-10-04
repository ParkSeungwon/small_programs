#include<sys/unistd.h>
#include<fcntl.h>
#include<chrono>
#include<thread>
using namespace std;

int main()
{
	char buffer[11] = {0,};
	
	for(int i=0; i<10; i++) {
		this_thread::sleep_for(1s);
		write(0, "dd", 3);
	}
}
