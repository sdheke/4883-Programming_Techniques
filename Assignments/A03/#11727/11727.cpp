// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 08/31/2020
// In this program, we are given the salaries of these 
// 3 employees working in the accounts department. You
// have to find out the salary of the person who survives.

#include<iostream>

using namespace std;

int main()
{
	long long num;

	int i;
	long long num1,num2,num3;

	cin>>num;
	
	for(i=1; i<=num; i++)
	{
		cin>>num1>>num2>>num3;

		
		if((num1>num2 && num1<num3) || (num1<num2 && num1>num3)){
			cout<<"Case "<<i<<": "<<num1<<endl;
		}
			else if((num2>num1 && num2<num3) || (num1>num2 && num2>num3)){
				cout<<"Case "<<i<<": "<<num2<<endl;
			}
				else if((num3>num1 && num3<num2)|| (num3<num1 && num3>num2)){
				cout<<"Case "<<i<<": "<<num3<<endl;
			}
		
	}
	
	return 0;	
}