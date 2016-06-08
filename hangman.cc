#include <chrono>
#include <random>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

class Hang
{
public:
	Hang(const char* filename) {
		char c;
		ifstream file(filename);
		while(file >> word) {
			word.erase(word.size()-1, 1);
			while(c != '\n' ) {
				def += c;
				file >> noskipws >> c;
			}
			words[word] = def;
			def = ""; c = ' '; 
		}
		set_word();
	}

	bool ask() {
		cout << "단어: ";
		bool correct = print_word();
		cout << "힌트: " + def << endl;
		cout << "사용가능한 문자 : ";
		print_alphabet();
		char c;
		cin >> c;
		entered.insert(c);
		return correct;
	}


protected:
	string word, def;
	map<string, string> words;
	set<char> entered;

private:
	bool print_word() {
		bool correct = true;
		for(auto& a : word) {
			if(entered.find(a) != entered.end()) cout << a;
			else {
				cout << '_';
				correct = false;
			}
		}
		cout << endl;
		return correct;
	}

	void print_alphabet() {
		for(int i=0; i<26; i++) {
			if(entered.find(char('a'+i)) == entered.end()) cout << char('A' + i);
			else cout << '_';
		}
		cout << endl;
	}

	void set_word() {
		uniform_real_distribution<> nd(0, words.size());
		knuth_b e(chrono::system_clock::now().time_since_epoch().count());
		auto it = words.begin();
		for(int i=0; i<nd(e); i++) it++;
		word = it->first;
		def = it->second;
	}
};

int main()
{
	Hang h("word.txt");
	while(!h.ask());
}
