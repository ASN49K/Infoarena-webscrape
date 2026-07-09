#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out")
int v[1050],v1[1050],i,j,n,m,k,t,p,r,st[1050];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=m;i++)
        f>>v1[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(v[i]==v1[j])
        {
            k++;
            st[k]=v[i];
        }
    }
    g<<k<<endl;
    for(i=1;i<=k;i++)
        g<<st[i]<<" ";
}
