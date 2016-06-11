#include<random>
#include<algorithm>
#include<iostream>
using namespace std;

class Card
{
public:
	int num;
	char c;
	bool operator<(const Card& r) const {//const const needed
		if(num == r.num) return comp_c() < r.comp_c();
		else return comp_n() < r.comp_n();
	}
	bool operator==(const int r) const {
		if(num == r) return true;
		else return false;
	}

protected:
private:
	char comp_c() const {
		if(c == 'C') return 'E';
		else return c;
	}
	int comp_n() const {
		if(num == 1) return 14;
		else return num;
	}
};

auto f = [](Card a, Card b) { return !(a<b); };


pair<int, Card> analyse(array<Card, 5> h) {
	bool  four_card = false, flush = false, straight = false, 
		  triple = false, two_pair = false, one_pair = false;
	sort(h.begin(), h.end(), f);
	flush = true;
	for(int i=0; i<4; i++) if(h[i].c != h[i+1].c) flush = false;
	sort(h.begin(), h.end(), [](Card a, Card b) { return a.num < b.num; });
	int serial = 0;
	for(int i=0; i<4; i++)	if(h[i].num == h[i+1].num - 1) serial++; 
	if(serial == 4) straight = true;
	else if(h[0].num == 1 && h[1].num == 10 && serial == 3) straight = true;
	if(flush || straight) sort(h.begin(), h.end(), f);
	for(int i=0, c=0; i<5; i++) {
		if(straight) break;
		if(i < 4 && h[i].num == h[i+1].num) c++;
		else {
			if(c == 3) four_card = true;
			else if(c == 2) triple = true;
			else if(c == 1) {
				if(one_pair != true) one_pair = true;
				else two_pair = true;
			}
			c = 0;
		}
	} 
	//for(auto& a : h) cout << a.c << a.num << ' ';
	int point = 0;
	if(four_card) {
		remove_if(h.begin(), h.end(), [&h](Card a) { 
				return count(h.begin(), h.end(), a.num) == 1;});
		sort(h.begin(), h.begin()+4, f);
		point += 6;
		cout << "4card ";
	} else if(flush) {
		point += 5;
		cout << "flush ";
	} else if(one_pair && triple) {
		remove_if(h.begin(), h.end(), [&h](Card a) {
				return count(h.begin(), h.end(), a.num) == 2;});
		sort(h.begin(), h.begin()+3, f);
		point += 4;
		cout << "full house ";
	} else if(two_pair) {
		remove_if(h.begin(), h.end(), [&h](Card a) {
				return count(h.begin(), h.end(), a.num) == 1;});
		sort(h.begin(), h.begin()+4, f);
		point += 2; 
		cout << "two_pair ";
	} else if(one_pair) {
		remove_if(h.begin(), h.end(), [&h](Card a) {
				return count(h.begin(), h.end(), a.num) == 1;});
		sort(h.begin(), h.begin()+2, f);
		point += 1;
		cout << "one pair ";
	}

	if(straight) {
		point += 3;
		cout << "straight ";
	}
	cout << endl;
	return make_pair(point, h[0]);
}

int main()
{
	Card card;
	array<Card, 52> deck;
	array<Card, 5> player1, player2;
	char g[4] {'C', 'D', 'H', 'S'};
	for(int i=0, k=0; i<4; i++) {
		for(int j=1; j<14; j++) {
			card.num = j;
			card.c = g[i];
			deck[k++] = card;
		}
	}

	shuffle(deck.begin(), deck.end(), random_device());
//	sort(deck.begin(), deck.begin()+5, f);
//	sort(deck.begin()+5, deck.begin()+10, f);
	cout << "Player 1 has : ";
	for(int i=0; i<5; i++) cout << deck[i].c << deck[i].num << ' ';
	cout << endl;
	cout << "Player 2 has : ";
	for(int i=5; i<10; i++) cout << deck[i].c << deck[i].num << ' ';
	cout << endl;
//	player1.resize(5);//resize before copy
//	player2.resize(5);
	copy_n(deck.begin(), 5, player1.begin());
	copy_n(deck.begin()+5, 5, player2.begin());
	auto p1 = analyse(player1);
	auto p2 = analyse(player2);
	if(p1.first == p2.first) {
		if(p1.second < p2.second) cout << "Player 2 won !!" << endl;
		else cout << "Player 1 won !!" << endl;
	} else if(p1.first < p2.first) cout << "Player 2 won !!" << endl;
	else cout << "Player 1 won !!" << endl;
}


