#include<iostream>
#include<string>
using namespace std;

class Tel
{
public:
	string name;
	string tel;
	bool operator<(const Tel& rs) {	return name.compare(rs.name) < 0; }
	Tel* left = nullptr;
	Tel* right = nullptr;
};

class Tree
{
public:
	Tel* root = nullptr;
	void insert(Tel& t) { insert(t, root); }
	void show() { show(root); }
	void search(string nm) { search(nm, root); }

private:
	void insert(Tel& t, Tel*& node) {//node를 전달하기 위해 & 반드시 必要
		if(node == nullptr) node = &t;	
		else if(*node < t) insert(t, node->right);
		else insert(t, node->left);
	}
	void search(string nm, Tel* node) {
		if(node->name.compare(nm) == 0) cout << node->name << ':' << node->tel << endl;
		else if(node->name.compare(nm) < 0) search(nm, node->right);
		else search(nm, node->left);
	}
	void show(Tel* node) {
		if(node != nullptr) cout << node->name << ':' << node->tel << endl;
		if(node->left != nullptr) show(node->left);
		if(node->right != nullptr) show(node->right);
	}
};

int main()
{
	Tel james, Amy, Chris;
	james.name = "james";
	james.tel = "02-233-2232";
	Amy.name = "Amy";
	Amy.tel = "331312";
	Chris.name = "Chris";
	Chris.tel = "013232324";
	Tree tree;
	tree.insert(james);
	tree.insert(Amy);
	tree.insert(Chris);
	tree.show();
	tree.search("Amy");
	tree.search("Chris");
}
