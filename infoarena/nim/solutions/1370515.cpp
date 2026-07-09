#include<cstdio>
#include<fstream>
using namespace std;
long t,j,n,a,xorsum,i;
int main()
{
    ifstream f("nimc.in");
    ofstream g("nimc.out");
f>>t;
for(j=1;j<=t;j++)
    {f>>n;
    for(i=1;i<=n;i++)
        {f>>a;
        xorsum=xorsum^a;}
    if(xorsum==0)
        g<<"NU"<<'\n';
    else
        g<<"DA"<<'\n';
    }
return 0;
}
