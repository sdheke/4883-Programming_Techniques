// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 09/18/2020
// Problem 11988

#include <iostream>
#include <stdio.h>

using namespace std;

char L[100005];
int a[100005], b[100005];

int main() 
{
    while(gets(L+1)) 
    {
        int i;
        a[0] = b[0] = 0; 
        for(i = 1; L[i]; i++) {
            if(L[i] == '[')
                a[i] = 0, b[i] = b[0];
            else if(L[i] == ']')
                a[i] = a[0], b[i] = 0;
            else
                a[i] = i-1, b[i] = b[i-1];
            a[b[i]] = i, b[a[i]] = i;
        }
        for(i = b[0]; i; i = b[i])
            if(L[i] != '[' && L[i] != ']')
            putchar(L[i]);
        puts("");
    }
    return 0;
}