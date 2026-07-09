#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int i,t,x,y,z;
f>>t;
for(i=1;i<=t;i++)
{f>>x>>y;
   while(y!=0)
   {z=x%y;
    x=y;
    y=z;}

g<<x<<endl;
}
    return 0;
}
