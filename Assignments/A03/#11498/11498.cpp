// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 08/31/2020

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	
	//not acccpeted or solve
	long long t,n,m,x,y;
	long long nx,ny;
	
	while(cin>>t)
	{
		if(t==0) break;
		cin>>n>>m;
		while(t--)
		{
			cin>>x>>y;
			
			if(x== n || y==m)
{
				 cout<<"divisa"<<endl;
			}
			else{
				
				if(x>=n && y>=m) cout<<"NE"<<endl;
				else if(x>=n && y<m) cout<<"SE"<<endl;
				else if(x<n && y<m) cout<<"SO"<<endl;
				else if(x<n && y>=m) cout<<"NO"<<endl;
			}
			
		}
	}
	
	return 0;
}