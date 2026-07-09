#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void elimin (int v[],int k,int &n)
{int i;
for(i=k;i<n;i++)
    v[i]=v[i-1];
n--;

}
int main()
{int v[100],q,y,n,m,i,j,nr=0,x[100],c[100];
f>>n>>m;
for(i=i;i<=n;i++)
    f>>v[i];
for(j=1;j<=m;j++)
    f>>x[j];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(v[i]==x[j])
    {nr++;
        c[nr]=v[i];

    elimin(x,j,m);}
    g<<nr<<endl;
    for(i=1;i<=nr;i++)

        g<<c[nr]<<" ";
f.close();
g.close();
}
