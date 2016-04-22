#pragma once
#include <string>
#include <vector>

class WordMatch
{
public:
	WordMatch(std::string w, std::string m, int c);
	static int least;
	std::vector<std::string> course;
	static std::vector<std::string> cs;

	void match();

protected:
	std::string word, to_match;
	int c;

private:
	void leave();
	void insert();
	void chg();
	void del();
};


