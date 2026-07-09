#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[100],b[100],ma[260][260],n,m,v[100],p=0;
int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]!=b[j])
                ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            else if(a[i]==b[j])
            {
                ma[i][j]=ma[i-1][j-1]+1;
                p++;
                v[p]=a[i];
            }
    out<<p<<"\n";
    for(int i=1;i<=p;i++)
        out<<v[i]<<" ";
    return 0;
}
