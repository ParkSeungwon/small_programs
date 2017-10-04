#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<title>Hello World - First CGI Program</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h2>Hello World! This is my first CGI program</h2>\n";
	string s;
	cin >> s;
	cout << s;
   cout << "</body>\n";
   cout << "</html>\n";
}
