// Sabin Dheke
// CMPS 4883
// Top in CS: Prog. Tech
// Fall 29020
// Professor Terry Griffin
// Due date: 10/21/2020
// Problem 10183

// For this problem, i took little help from online.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std ;

#define MaxTerm 1000

vector<string> fibs;

string add(string str1, string str2) {
  while (str1.length() < str2.length())
    str1 = '0' + str1;
  while (str2.length() < str1.length())
    str2 = '0' + str2;

  string remainder = "";
  int  quotient = 0;
  for (int i = str1.length()-1; i >= 0; i--) 
  {
    int sum = quotient + (str1[i]-'0') + (str2[i]-'0');
    quotient = sum / 10;
    sum = sum % 10;
    remainder = (char)(sum+'0') + remainder;
  }
  if (quotient) remainder  = '1' + remainder;
  return remainder;
}

bool smaller(string str1, string str2) 
{
  while (str1.length() < str2.length())
    str1 = '0' + str1;

  while (str2.length() < str1.length())
    str2 = '0' + str2;

  for (int i = 0; i < str1.length(); i++) 
  {
    if (str2[i] < str1[i]) 
        return false;

    if (str2[i] > str1[i]) 
        return true;
  }
  return true;
}

int main() 
{
  fibs.push_back("1");
  fibs.push_back("2");
  for (int i = 0; i < 500; i++) 
  {
    fibs.push_back(add(fibs[fibs.size()-2], fibs[fibs.size()-1]));
  }

  string str1, str2;
  while (cin >> str1 >> str2) 
  {
    if (str1 == "0" && str2 == "0") 
        break;

    int count = 0;
    for (int i = 0; i < fibs.size(); i++)
    {
      if (smaller(str1, fibs[i]) && smaller(fibs[i], str2))
        count++;
    }
    cout << count << endl;
  }
  return 0;
}