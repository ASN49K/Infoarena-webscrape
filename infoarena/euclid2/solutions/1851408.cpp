#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
   int n,x,y,r,i;
   fin>>n;
   for(i=1;i<=n;i++)
     {fin>>x>>y;
    while(y!=0) {r=x%y; x=y; y=r;}
     fout<<x<<"\n";
     }
    return 0;
}
