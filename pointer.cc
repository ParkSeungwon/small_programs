struct T {
	int data;
	T* next;
};

int main() {
	T i;
	T* p = &i;
	T **pp = &p;
	T** p2 = &i.next;
	T** p3 = &p->next;
	
}
