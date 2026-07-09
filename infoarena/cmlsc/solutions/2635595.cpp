#include <iostream>
#include <fstream>
using namespace std;
int v1[1025],v2[1025];
int main()
{
    int m,n,x,k=0,i,v3[1025];
    ifstream f("cmlsc.in");
    ifstream g("cmlsc.out");
    f>>n;
    f>>m;
    for(i=1;i<=n;i++)
    {
        f>>x;
        v1[x]++;
    }
    for(i=1;i<=m;i++)
    {
        f>>x;
        v2[x]++;
    }
    for(i=1;i<=256;i++)
    {
        if(v1[i]==v2[i] && v1[i]!=0)
            {
                k++;
            v3[k]=i;
            }
    }
    g<<k<<endl;
    for(i=1;i<=k;i++)
        g<<v3[i]<<" ";
}
