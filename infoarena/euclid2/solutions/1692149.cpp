#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int i,j,n,y;
    f>>y;
    for(y;y;--y)
    {
    f>>i>>j;
    if(i>j)
       {
         n=i;
         i=j;
         j=n;
       }
       while(i)
       {
           swap(i,j);
           i=i%j;

       }
        g<<j<<endl;
    }
    return 0;
}
