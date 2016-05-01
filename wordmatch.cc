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
		int sz = to_match.size();
		c += sz;
		if(least > c) {
			least = c;
			cs = course;
			if(sz > 0) cs.push_back("delete " + to_match);
		}
	} else if(to_match.size() == 0) insert();
	else {
		if(word[0] == to_match[0]) leave();
		else chg();
		insert();
		del();
	}
}

void WordMatch::leave() const
{
	WordMatch w(word.substr(1), to_match.substr(1), c);
	w.course = course;
	w.course.push_back(string("leave ") + word[0]);
	w.match();
}

void WordMatch::insert() const 
{
	WordMatch w(word.substr(1), to_match, c+1);
	w.course = course;
	w.course.push_back(string("insert ") + word[0]);
	w.match();
}

void WordMatch::chg() const
{
	WordMatch w(word.substr(1), to_match.substr(1), c+1);
	w.course = course;
	w.course.push_back(string("change ") + to_match[0] + " -> " + word[0]);
	w.match();
}

void WordMatch::del() const
{
	int i = to_match.find(word[0], 1);
	if(i != string::npos) {
		WordMatch w(word.substr(1), to_match.substr(i+1), c + i);
		w.course = course;
		w.course.push_back("delete " + to_match.substr(0,i) + " -> " + word[0]);
		w.match();
	}
}

int main()
{
	string s1, s2;
	cout << "word to match?  ";
	cin >> s1;
	cout << "word to change? ";
	cin >> s2;
	WordMatch w(s1, s2);
	w.match();
	for(auto& a : w.cs) cout << a << endl;
	cout << w.least << " operation needed." << endl;
}
