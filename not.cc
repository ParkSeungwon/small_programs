class String
{
public:
	String(const char* s) {} 
	operator const char*() {}
};


int main(){
	String s("Hello!");
	const char* sz = s;
}

