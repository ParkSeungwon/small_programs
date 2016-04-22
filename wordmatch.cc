#include <iostream>
#include <vector>
#include "wordmatch.h"
using namespace std;

int WordMatch::least = 100;
vector<string> WordMatch::cs = {};

WordMatch::WordMatch(string w, string m, int c) 
{
	word = w; 
	to_match = m; 
	this->c = c;
}

void WordMatch::match() 
{
	if(word.size() == 0) {
		c += to_match.size();
		if(least > c) {
			least = c;
			cs = course;
		}
	} else if(to_match.size() == 0) insert();
	else {
		if(word[0] == to_match[0]) leave();
		else chg();
		insert();
		del();
	}
}

void WordMatch::leave() 
{
	WordMatch w(word.erase(0,1), to_match.erase(0,1), c);
	w.course = course;
	w.course.push_back("leave");
	w.match();
}

void WordMatch::insert() 
{
	WordMatch w(word.erase(0,1), to_match, c+1);
	w.course = course;
	w.course.push_back("insert");
	w.match();
}

void WordMatch::chg() 
{
	WordMatch w(word.erase(0,1), to_match.erase(0,1), c+1);
	w.course = course;
	w.course.push_back("change");
	w.match();
}

void WordMatch::del() 
{
	int i = to_match.find(word[0], 1);
	cout << word << endl;
	cout << "found " << word[0] << " at " << i << endl;
	if(i != string::npos) {
		WordMatch w(word.erase(0,1), to_match.erase(0, i), c + i - 1);
		w.course = course;
		w.course.push_back("delete" + to_string(i-1));
		w.match();
	}
}

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	cout << s1.erase(0,1) << endl;
	cout << s1[0] << s2[0] << endl;
	WordMatch w(s1, s2, 0);
	w.match();
	for(auto& a : w.cs) cout << a << endl;
	cout << w.least << endl;
}
