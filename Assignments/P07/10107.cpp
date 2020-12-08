// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 10/21/2020
// Problem 10107

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std ;

void insertionSort( int *num, int i )
{
	while( i > 1 && num[ i ] < num[ i - 1 ] )
	{
		swap( num[ i ] , num[ i - 1 ] ) ;
		i-- ;
	}
}

int main()
{
	int	num[10001] = { 0 }; int N = 0; int i = 0;

	for( i = 1 ; cin >> num[ i ] ; i++ )
	{
		insertionSort( num, i ) ;
		
		if( i % 2 == 0 )
		{
			cout << ( num[ i / 2 ] + num[ i / 2 + 1 ] ) / 2 << endl ;
		}
		else
		{
			cout << num[ (i+1) / 2 ] << endl ;
		}
	}

	return 0 ;
}