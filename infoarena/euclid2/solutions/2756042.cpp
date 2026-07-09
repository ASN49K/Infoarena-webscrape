#include <iostream>

using namespace std;
int main()
{
int a, b, t, rest;
cin >> t;
for (int i = 1; i <= t; i++)
 {
 cin >> a >> b;
  while (b != 0)
   {
     rest = a % b;
     a = b;
     b = rest;
   }
   cout << a ;
 } 
 return 0;
}