#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream f("euclid.in");
   ofstream g("euclid.out");
   int n;
   int x, y, z;
   for(int i=1; i<=n; i++)
   {
       f >> x >> y;
       while(x!=y)
       {
           z = x%y;
           x = y;
           y = z;
       }
       g << x << "\n";
   }     
    return 0;
}