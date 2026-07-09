#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream c("euclid2.out");
int divizor(int x,int y)
{int r;
r=x%y;
while(r!=0)
   {
   x=y;
    y=r;
    r=x%y;
   }
c<<y<<endl;
}
int main ()
{
    int T,a,b,i;
    f>>T;
    for(i=1;i<=T;i++)
   {
    f>>a>>b;
    divizor(a,b);
   }
    return 0;
}
