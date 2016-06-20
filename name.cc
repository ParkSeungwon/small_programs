#include<iostream>
using namespace std;
namespace Stack {
	const int max_size = 200;
	char v[max_size];
	int top = 0;
	void push(char c);
	char pop();
}

void Stack::push(char c) 
{
	if(top <= 200) v[top++] = c; 
}

char Stack::pop()
{
	if(top >= 1) return v[--top];
}

int main()
{
	Stack::push('c');
	cout << Stack::pop() << endl;
}
