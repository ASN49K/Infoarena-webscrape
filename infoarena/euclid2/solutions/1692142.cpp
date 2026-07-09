#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int i,j,n;
    f>>i>>j;
    if(i>j)
       {
         n=i;
         i=j;
         j=n;
       }
       while(i)
       {
           j=j%i;
           if(j==0)
           {
               g<<i;
               return 0;
           }
           i=i%j;
       }
        g<<j;
    return 0;
}
