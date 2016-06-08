#include<iostream>
#include<utility>
#include<vector>
using namespace std;

struct Path {
	int me;//꼭지점 번호 
	int vC = 0, vS = 0;//가중치 
	Path* child = nullptr;
	Path* sibling = nullptr;
};

class Tree
{
public:
	Path* root = nullptr;
	~Tree() { 
		ins_ptr(root);
		for(auto& a : v) delete a;
	}

	void insert(int start, int distance, int destination) {
		Path* s;
		if(root == nullptr) {
			s = new Path();
			s->me = start;
			s->vC = distance;
			root = s;
			s = new Path();
			s->me = destination;
			root->child = s;
		} else {
			auto a = search(start);
			s = new Path();
			s->me = destination;
			insert(a.first, distance, s); 
		}
	}
	pair<Path*, int> search(int n) { return search(n, root, 0); }
	void show() { show(root); }

private:
	vector<Path*> v;
	void ins_ptr(Path* node) {
		v.push_back(node);
		if(node->child != nullptr) ins_ptr(node->child);
		if(node->sibling != nullptr) ins_ptr(node->sibling);
	}

	void insert(Path* node, int distance, Path* to_insert) {
		if(node->child == nullptr) {//empty
			node->child = to_insert;
			node->vC = distance;
		} else if(node->vC > distance) {//insert between
			to_insert->sibling = node->child;
			to_insert->vS = node->vC - distance;
			node->vC = distance;
			node->child = to_insert;
		} else ins_sibling(node->child, distance - node->vC, to_insert);
	}
	void ins_sibling(Path* node, int distance, Path* to_insert) {
		if(node->sibling == nullptr) {//empty
			node->vS = distance;
			node->sibling = to_insert;
		} else if(node->vS <= distance) {//track down
			ins_sibling(node->sibling, distance - node->vS, to_insert);
		} else {//insert between
			to_insert->sibling = node->sibling;
			to_insert->vS = node->vS - distance;
			node->vS = distance;
			node->sibling = to_insert;
		}
	}

	void show(Path* node) { 
		cout << node->me << ' '; 
		if(node->child != nullptr) show(node->child);
		if(node->sibling != nullptr) show(node->sibling);
	}
		
	pair<Path*, int> search(int n, Path* node, int dis) {
		cout << node->me << ' ' << dis << endl;
		if(node->me == n) {
//			cout << n << '=' << dis << ' ';
			return make_pair(node, dis);
		}
		if(node->child != nullptr) return search(n, node->child, node->vC + dis);
		if(node->sibling != nullptr) return search(n, node->sibling, node->vS + dis);
		return make_pair(nullptr, 0);
	}
};

int main()
{
	Tree tree;
	tree.insert(1, 3, 2);
	tree.insert(2, 4, 7);
	tree.insert(7, 5, 8);
	tree.insert(1, 1, 10);
	tree.insert(1, 7, 13);
	auto a = tree.search(2);
//	auto b = tree.search(13);
	cout << a.second << " to go to 8" << endl;
//	cout << b.second << " to go to 8" << endl;
	tree.show();
}
