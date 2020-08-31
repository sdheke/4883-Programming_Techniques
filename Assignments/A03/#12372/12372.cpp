// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 08/31/2020
// In this program, we are used to have a lot of 
// problems packing the suitcase for holiday, 
// so are checking the size of the suitcase.

#include<iostream>

using namespace std;

int main()
{
	long long num,i;
  long long length,width,breath;
	
	cin>>num;
	for(i=0; i<num; i++)
	{
		cin>>length>>width>>breath;
		
		if(length<=20 && width<=20 && breath<=20)
		{
			cout<<"Case "<<i+1<<": good"<<endl;
		}
		else {
			cout<<"Case "<<i+1<<": bad"<<endl;
		}
	}
}