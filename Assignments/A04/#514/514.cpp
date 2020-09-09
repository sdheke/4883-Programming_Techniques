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


using namespace std;

int main(void) 
{
  int num;
  int car;
  bool good;
  int train[1010];
  stack<int> str;
 
  while (cin >> num) 
  {
    if (num == 0)
      break;
 
    while (cin >> train[0])
     {
      if (train[0] == 0)
        break;
 
      while (!str.empty())
        str.pop();
 
      car = 1;
    good = true;
 
      for (int i = 1; i < num; i++)
        cin >> train[i];
 
      for (int i = 0; i < num; i++)
       {
        if (train[i] == car)
        {
          car++;
          continue;
        } 
        else if (train[i] < car) 
        {
          if (str.size() > 0) {
            if (str.top() == train[i]) 
            {
              str.pop();
              continue;
            }
          }
          good = false;
          break;
        } else if (train[i] > car)
         {
          while (train[i] != car)
           {
            str.push(car);
            car++;
          }
          car++;
          continue;
        }
      }
      
      if (good)
       {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
 
    cout << endl;
  }
 
  return 0;
}