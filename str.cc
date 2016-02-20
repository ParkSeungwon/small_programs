#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	while(s != "end") {
		cout << " 문자열을 입력하십시오\n";
		cin >> s;
		cout << "문자열의 길이는 " << s.size() << "입니다." << endl;
	}
	return 0;
}
