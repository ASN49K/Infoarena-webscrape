#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[30000],b[30000],c[30000];
int main()
{int i,j,k,x,nr=1;
f>>n>>m;
for(i=1;i<=n;i++)
    f>>a[i];
for (i=1;i<=m;i++)
    f>>b[i];
    k=1;
for(i=1;i<=n;i++)
{
    for(j=k;j<=m;j++)
        if(a[i]==b[j])
        {
            if(x!=i)
                {c[nr++]=a[i];
                k=j;
                x=i;
                }
        }
}
nr--;
g<<nr<<"\n";
for (i=1;i<=nr;i++)
    g<<c[i]<<" ";


    return 0;
}
