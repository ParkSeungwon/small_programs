#include <iostream>
using namespace std;

struct Stack {
	int top=0;
	int arr[20];
	void push(int n) {
		arr[top++] = n;
	}
	void pop() {
		top--;
	}
	void show() {
		cout << '[';
		for(int i=0; i<top; i++) cout << arr[i] << ',';
		cout << "\b]" << endl;
	}
} st;

int climb(int n) {
	if(n < 1) {
		if(!n) st.show();
		st.pop();
		return 0;
	} 
	st.push(1), climb(n-1);
	st.push(2), climb(n-2);
	st.push(3), climb(n-3);
	st.pop();//back to parents
}

int main(int c, char** v) {
	climb(atoi(v[1]));
}

