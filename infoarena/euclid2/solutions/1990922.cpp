#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int  cmmdc (int x,int y)
{
    if (y==0) return x;
    return cmmdc(y,x%y);
}
int main()
{int i,n,x,y;
   fin>>n;
   for (i=1;i<=n;i++)
   {
       fin>>x>>y;
       fout<<cmmdc(x,y)<<"\n";
   }
    return 0;
}
