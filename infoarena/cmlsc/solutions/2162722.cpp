#include <iostream>
#include <fstream>
using namespace std;
int v1[1030],v2[1030],f1[260],f2[260],i,m,n,mx,l,c[260],j;
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n>>m;
    for(i=1;i<=n;i++)
    {
        in>>v1[i];
        if(mx<v1[i])
        {
            mx=v1[i];
        }
        f1[v1[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        in>>v2[i];
        if(mx<v2[i])
        {
            mx=v2[i];
        }
        f2[v2[i]]++;
    }
    for(i=1;i<=mx;i++)
    {
        if(f1[i]!=0 && f2[i]!=0)
        {
            l++;
            c[j]=i;
            j++;
        }
    }
    out<<l<<"\n";
    for(i=0;i<j;i++)
    {
        if(c[i]!=0)
        {
            out<<c[i]<<" ";
        }
    }
    return 0;
}
