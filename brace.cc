#include<stack>
#include<string>
#include<iostream>
using namespace std;

template <typename T>
class Stack : public stack<T>
{
public:
	T pop() {
		T r = stack<T>::top();
		stack<T>::pop();
		return r;
	}
};

bool ok(string cal) {
	Stack<char> braces;
	for(auto& a : cal) {
		switch(a) {
			case '[': case '{': case '(': braces.push(a);		 	break;
			case ']': if(braces.pop() != '[') return false; 		break;
			case '}': if(braces.pop() != '{') return false;			break;
			case ')': if(braces.pop() != '(') return false; 		break;
			default: break;
		}
	}
	if(braces.empty()) return true;
	else return false;
}

int main()
{
	string s = "{(4+4)*3}";
	cout << (ok(s) ? "ok" : "wrong");
	s = "{(4+4)*[3}]";
	cout << (ok(s) ? "ok" : "wrong");
}
