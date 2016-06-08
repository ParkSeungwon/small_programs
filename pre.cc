#include <stdio.h>
#include <stdlib.h>

struct Item
{
	char c;
	int i;
	Item *next;
};

void delete_next(Item* it)
{
	Item* t = it->next->next;
	free(it->next);
	it->next = t;
}

Item* insert_next(Item* it, char c, int i)
{
	Item* t = it->next;
	it->next = (Item*)malloc(sizeof(Item));
	Item* u = it->next;
	u->c = c;
	u->i = i;
	u->next = t;
	return u;
}

Item* create_queue(const char* expression)
{
	Item* start = (Item*)malloc(sizeof(Item));
	start->c = 's';
	start->next = (Item*)malloc(sizeof(Item));
	start->next->c = 'e'; //s+-34233*44e
	Item* it = start;
	for(int i=0; expression[i] != '\0'; i++) {
		if(expression[i] >= '0' && expression[i] <= '9') {
			insert_next(it, 'i', expression[i] - '0');
		} else insert_next(it, expression[i], 0);
		it = it->next;
	}
	return start;
}
	
void print_queue(Item* item)
{
	Item* it = item;
	it = it->next;
	while(it->c != 'e') {
		if(it->c == 'i') printf("%d", it->i);
		else printf("%c", it->c);
		it = it->next;
	}
	printf("\n");
}

void clean_queue(Item* it)
{
	while(it->next->c != 'e') delete_next(it);
	delete_next(it);
	free(it);
}

Item* calcul(Item* it)
{
	Item* t = it->next;
	char c = t->c;
	t = t->next;
	int a = t->i;
	t = t->next;
	int b = t->i;
	int r;
	switch(c) {
		case '+': r = a+b; break;
		case '-': r = a-b; break;
		case '*': r = a*b; break;
		case '/': r = a/b; break;
	}
	delete_next(it);
	delete_next(it);
	delete_next(it);
	return insert_next(it, 'i', r);
}

bool scan_queue(Item* item)
{
	Item *it, *save, *entry_point;
	int cal = 0, num = 0;
	bool done = false;
	it = item;
	while(it->c != 'e') {
		save = it;
		it = it->next;
		if(it->c != 'i') {
			entry_point = save;
			cal = 1;
			num = 0;
		} else num++;
		if(cal == 1 && num == 2) {
			cal = 0; num = 0;
			done = true;
			it = calcul(entry_point);
		}
	}
	return done;
}	
	


int main(int argc, char** argv)
{
	Item* it = create_queue("-+*8+17*+3752");
	print_queue(it);
	while(scan_queue(it)) print_queue(it);
	clean_queue(it);
	if(argc > 1) {
		it = create_queue(argv[1]);
		print_queue(it);
		while(scan_queue(it)) print_queue(it);
		clean_queue(it);
	}
}






