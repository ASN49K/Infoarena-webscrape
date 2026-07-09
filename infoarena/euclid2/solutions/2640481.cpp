#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
   
int main()
{

   int n;
   int x, y, z;
   cin >> n;
   for(int i=1; i<=n; i++)
   {
       fin >> x >> y;
       while(x!=y)
       {
           z = x%y;
           x = y;
           y = z;
       }
       fout << x << "\n";
   }     
    return 0;
}