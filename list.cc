#include<iostream>
#include<memory>
using namespace std;

class Exception : public exception
{
public:
	Exception(string s) { msg = s;}
	virtual const char* what() const throw() {
		return msg.c_str();
	}

private:
	string msg;
};

template <typename T> class List
{
public:
	T pop() {
		if(!next) throw Exception("popup empty");
		data = next->data;
		next = next->next;
		return data;
	}
	void push(T n) {
		shared_ptr<List<T>> a{new List<T>};
		a->data = n;
		a->next = next;
		next = a;
	}
	void insert(T n) {
		next = insert(next, n);
	}
	void show() {
		for(auto a = next; a; a = a->next) cout << a->data << ' ';
		cout << endl;
	}
	void push_back(T n) {
		next = push_back(next, n);
	}

protected:
	T data;
	shared_ptr<List<T>> next = nullptr;

private:
	shared_ptr<List<T>> insert(shared_ptr<List<T>> p, T n) {
		shared_ptr<List<T>> ptr(new List<T>);
		ptr->data = n;
		ptr->next = nullptr;
		if(!p) return ptr;
		else if(n < p->data) {
			p->next = insert(p->next, n);
			return p;
		} else {
			ptr->next = p;
			return ptr;
		}
	}

	shared_ptr<List<T>> push_back(shared_ptr<List<T>> p, T n) {
		if(!p) {
			shared_ptr<List<T>> ptr{new List<T>};
			ptr->data = n;
			ptr->next = nullptr;
			return ptr;
		} else {
			p->next = push_back(p->next, n);
			return p;
		}
	}

};


int main()
{
	List<int> li;
	for(int i=0; i<30; i++) li.push(i);
	li.insert(1);
	li.insert(3);
	li.insert(41);
	li.insert(4);
	li.show();
	li.push_back(23);
	for(int i=0; i<36; i++) {
		try {
			cout << li.pop() << endl;
		} catch(const Exception& e) {
			cout << e.what() << endl;
		}
	}
}
