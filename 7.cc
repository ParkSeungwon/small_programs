#include<vector>
#include<iostream>
using namespace std;

class DataException : public exception
{
public:
	DataException(const char* s) { this->s = s;}
	virtual const char* what() const throw() {
		return s;
	}
protected:
	const char* s;
};

template <typename T, int N> class Stack
{
public:
	void push(T n) {
		if(top == N) throw DataException("stack full");
		else arr[top++] = n;
	}
	void pop() {
		if(top == 0) throw DataException("stack empty");
		else top--;
	}
	void show() {
		for(int i=0; i<top; i++) cout << arr[i] << ' ';
	}

protected:
	T arr[N];
	unsigned int top=0;
};

template <typename T, int N> class Queue
{
public:
	void push(T n) { 
		if(!empty && back == top) throw DataException("Queue full");
		else {
			empty = false;
			arr[back] = n;
			pp(back);
		}
	}
	void pop() {
		if(empty) throw DataException("Queue empty");
		else {
			pp(top);
			if(top == back) empty = true;
		}
	}
	void show() {
		if(!empty) {
			cout << arr[top] << ' ';
			for(int i=top+1; i != back; pp(i)) cout << arr[i] << ' ';
		}
	}

protected:
	T arr[N];
	int top = 0, back = 0;
	bool empty = true;
	void pp(int& n) {
		if(n == N-1) n = 0;
		else n++;
	}

};

int main()
{
	Stack<int, 10> st;
	for(int i=0; i<8; i++) st.push(i);
	st.show();

	Stack<char, 5> stc;
	stc.push('c');
	stc.push('a');
	stc.pop();
	stc.show();

	Queue<char, 5> q;
	for(int i=0; i<5; i++) q.push('c' + i);
	q.pop();
	q.show();
}
