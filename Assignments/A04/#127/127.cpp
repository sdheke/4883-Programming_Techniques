// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/09/2020
// Problem 127

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
 
int main() {
 
	string n;
	while (cin >> n) {
		if (n[0] == '#')
			break;
		vector<stack<string> > card;
		stack<string> str;
		str.push(n);
		card.push_back(str);
		for (int i = 1; i < 52; i++) 
		{
			stack<string> str;
			cin >> n;
			str.push(n);
			card.push_back(str);
		}
 
		for (int i = 1; i < card.size(); i++) {
			if (i >= 3
					&& (card[i].top()[0] == card[i - 3].top()[0]
							|| card[i].top()[1] == card[i - 3].top()[1])) {
				card[i - 3].push(card[i].top());
				card[i].pop();
				if (card[i].empty())
					card.erase(card.begin() + i, card.begin() + i + 1);
				i -= 4;
			} else if (i >= 1
					&& (card[i].top()[0] == card[i - 1].top()[0]
							|| card[i].top()[1] == card[i - 1].top()[1])) {
				card[i - 1].push(card[i].top());
				card[i].pop();
				if (card[i].empty())
					card.erase(card.begin() + i, card.begin() + i + 1);\
				i -= 2;
			}
 
		}
 
		const int size = card.size();
		cout << size << " pile" << ((size == 1) ? " " : "str ") << "remaining:";
		cout << size << " piles" << ((size > 1) ? " " : "str ") << "remaining:";
		for (int i = 0; i < size; i++)
			cout << " " << card[i].size();
		cout << endl;

		
		
	}
	return 0;
}
