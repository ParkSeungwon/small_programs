#include<stdio.h>
#include<string.h>

struct Tel
{
	char *name;
	char *tel;
	Tel* left = NULL;
	Tel* right = NULL;
};

Tel* root = NULL;
void insert(Tel& t, Tel*& node) {//node를 전달하기 위해 & 반드시 必要
	if(node == NULL) node = &t;	
	else if(strcmp(node->name, t.name) > 0) insert(t, node->right);
	else insert(t, node->left);
}
void search(const char* nm, Tel* node) {
	if(strcmp(node->name, nm) == 0) printf("%s : %s\n", node->name, node->tel);
	else if(strcmp(node->name, nm) > 0) search(nm, node->right);
	else search(nm, node->left);
}
void show(Tel* node) {
	if(node != NULL) printf("%s : %s\n", node->name, node->tel);
	if(node->left != NULL) show(node->left);
	if(node->right != NULL) show(node->right);
}


void ins(Tel& t) { insert(t, root); }
void shw() { show(root); }
void srh(const char* nm) { search(nm, root); }

int main()
{
	Tel james, Amy, Chris;
	james.name = "james";
	james.tel = "02-233-2232";
	Amy.name = "Amy";
	Amy.tel = "331312";
	Chris.name = "Chris";
	Chris.tel = "013232324";
	ins(james);
	ins(Amy);
	ins(Chris);
	shw();
	srh("Amy");
	srh("Chris");
}
