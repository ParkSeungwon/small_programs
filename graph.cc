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
			search(start);
			s = new Path();
			s->me = destination;
			insert(search_result.first, distance, s); 
		}
	}
	void search(int n) { search(n, root, 0); }
	void show() { show(root); }
	pair<Path*, int> search_result;

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
		if(node->child != nullptr) {
			cout << node->me;
			cout << 'v' << node->vC << '=';
			show(node->child);
		}
		if(node->sibling != nullptr) {
			cout << node->me;
			cout << '-' << node->vS << '=';
			show(node->sibling);
		}
	}
		
	void search(int n, Path* node, int dis) {
		if(node->me == n) {
			search_result = make_pair(node, dis);
			return;
		}
		if(node->child != nullptr) search(n, node->child, node->vC + dis);
		if(node->sibling != nullptr) search(n, node->sibling, node->vS + dis);
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
	tree.insert(1, 7, 12);
	tree.insert(1, 7, 33);
	tree.insert(7, 7, 6);
	tree.insert(7, 4, 9);
	tree.insert(2, 7, 3);
	tree.insert(3, 2, 1);
	tree.search(2);
	cout << tree.search_result.second << " to go to " << tree.search_result.first->me << endl;
	tree.search(13);
	cout << tree.search_result.second << " to go to " << tree.search_result.first->me << endl;
	tree.search(9);
	cout << tree.search_result.second << " to go to " << tree.search_result.first->me << endl;
	tree.search(8);
	cout << tree.search_result.second << " to go to " << tree.search_result.first->me << endl;
	tree.show();
}
