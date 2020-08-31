// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 08/31/2020
// In this program, we are counting the donated money.
// Our target will be to collect as much as possible to help our friend.


#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<string.h>

using namespace std;

int main()
{
	int amount,total;
	int sum=0;
	char word[100];
	
	cin>>total;
	while(total--)
	{
		cin>>word;
		if(strcmp(word,"donate")==0)
		{
			cin>>amount;
			sum=sum+amount;
		}
		else cout<<sum<<endl;
	}
	
	return 0;
}