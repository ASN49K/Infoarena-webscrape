#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int i,t,x,y;
f>>t;
for(i=1;i<=t;i++)
{f>>x>>y;
   while(x!=y)
    if(x<y)
        y=y-1;
    else
        x=x-1;
g<<x<<endl;
}
    return 0;
}
