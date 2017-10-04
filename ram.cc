#include<iostream>
#include<cstring>
using namespace std;

class Ram
{
char mem[100*1024];
public:

~Ram();
char read(int address);
void write(int address, char value);
void show(int address);
};
Ram::~Ram()
{
cout << "메모리 제거됨" << endl;
}
char Ram::read(int address)
{
return mem[address];
}
void Ram::write(int address, char value)
{
mem[address] = value;
}
void Ram::show(int address)
{
cout << hex << &mem[address] << endl;
}


int main()
{
Ram ram;
ram.write(100, 90);
ram.write(101, 30);
char res = ram.read(100) + ram.read(101);
ram.write(102, res);
ram.write(103, res);
cout << "102 번지의 값 = " << ram.read(102) << endl;
ram.show(102); 
}
