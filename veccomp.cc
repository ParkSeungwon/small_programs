#include<algorithm>
#include<iostream>
#include<random>
using namespace std;

bool comp(int a, int b) { return a>b; }

int main()
{
	int deck[20];
	for(int i=1, j=0; i<11; i++) {//덱에 카드를 집어 넣는다.
		deck[j++] = i;
		deck[j++] = i;
	}
	shuffle(deck, deck+20, random_device());//섞는다.

	array<int, 5> player1, player2;
	copy_n(deck, 5, player1.begin());//카드를 나누어준다.
	copy_n(deck+5, 5, player2.begin());
	sort(player1.begin(), player1.end(), comp);
	sort(player2.begin(), player2.end(), comp);
	
	cout << "Player 1 has : ";//패를 보여준다.
	for(auto& a : player1) cout << a << ' ';
	cout << endl;
	cout << "Player 2 has : ";
	for(auto& a : player2) cout << a << ' ';
	cout << endl;

	if(player1 < player2) cout << "player2 win!" << endl;//승자결정 
	else cout << "player1 win!" << endl;
}
