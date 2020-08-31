// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 08/31/2020
// In this program, we are checking operator about the 
// relationship between two values and these operators
// are called relational operators.  First one is
// greater than the second (ii) First one is less 
// than the second or (iii) First and second one 
// is equal
 
#include <iostream>


using namespace std;

int main(){


    int num;
    cin >> num;

    for(int i = 1; i <= num; i++)
    {
        int left, right;
        cin >> left  >> right;
         if(left == right)cout << "=" << endl;
        if(left > right)cout << ">" << endl;
        if(left < right)cout << "<" << endl;
       
    }
    return 0;
}
