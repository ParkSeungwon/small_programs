#include <future>
using namespace std;
int main()
{
	auto f = async([](){return 3;});
	return f.get();
}
