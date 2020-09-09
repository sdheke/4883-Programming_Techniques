// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/09/2020
// Problem 727

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char cha) 
{
	if (cha == '(' || cha == ')')
		return 0;
	if (cha == '+' || cha == '-')
		return 1;
	if (cha == '*' || cha == '/')
		return 2;
	return -1;
}

void push_ip(stack<char> &input, char token, char postfix[], int &idx) {
	if (input.empty() || precedence(input.top()) < precedence(token))
   {
		input.push(token);
	} 
  else
   {
		while (!input.empty() && (precedence(input.top()) >= precedence(token)))
     {
			postfix[idx] = input.top();
			idx++;
			input.pop();
		}
		input.push(token);
	}
}

int main() 
{
	int num;
	int count = 0;

	cin >> num;
	cin.ignore();
	cin.ignore();

	while (num--) {
		count++;
		if(count >1) cout << endl;

		stack<char> input;
		char postfix[51];
		string token;
		int idx = 0;

		while (true) {
			getline(cin, token);
			if (token.length() == 0 || !cin)
				break;

			if (isdigit(token.at(0))) {
				postfix[idx] = token.at(0);
				idx++;
			} else if (token.at(0) == ')')
       {
				while (input.top() != '(') {
					postfix[idx] = input.top();
					idx++;
					input.pop();
				}
				input.pop();
			} else if (token.at(0) == '(')
       {
				input.push('(');
			} else {
				push_ip(input, token.at(0), postfix, idx);
			}
		}

		while (!input.empty()) 
    {
			postfix[idx] = input.top();
			idx++;
			input.pop();
		}
		postfix[idx] = '\0';

		cout << postfix << endl;
	}

	return 0;
}