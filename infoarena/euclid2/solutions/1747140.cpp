#include <iostream>
#include <fstream>
using namespace std;

/* Varianta 60 puncte



*/

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   int a, b, n;
   f>>n;
   for(int i = 0; i < n; i++)
   {
      f>>a>>b;
      while(a!=b)
      {
         if(a > b) a = a - b;
         else b = b - a;
      }

      g<<a<<endl;
   }
}
