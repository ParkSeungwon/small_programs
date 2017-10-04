#include<iostream>
#include<typeinfo>
using namespace std;
template <typename T, typename... Args> bool check_args(T a, Args... args)
{
	static string type;
	if(type == "") type = typeid(a).name;
	else if(type != typeid(a).name()) return false;
	else return check_args(args...);
}
int main(){}
