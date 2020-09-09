 // Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/09/2020
// Problem 673

#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int main()
{
    long num;
    string str;
    cin >> num;
    getchar();
    while(num--)
    {
        getline(cin , str);
        stack <char> str2;
        bool check = false;
        for(int i = 0; str[i]; i++)
        {
            if(str[i] == '(' || str[i] == '[')
                str2.push(str[i]);
            else if(str[i] == ')' || str[i] == ']')
            {
                if(!str2.empty() && str[i] == ')' && str2.top() == '(')
                    str2.pop();
                else if(!str2.empty() && str[i] == ']' && str2.top() == '[')
                    str2.pop();
                else { check = true;
                
                 break; }
            }
        }
        if(!str2.empty() || check)
            cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}