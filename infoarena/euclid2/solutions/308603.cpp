#include <fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,t,i;
int main()
{f>>t;
for(i=1;i<=t;i++)
{f>>a>>b;
while(b)
    {r=a%b;
    a=b;
    b=r;
    }
g<<a<<'\n';
}
return 0;



}
