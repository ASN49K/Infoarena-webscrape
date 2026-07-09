#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,x,a[1500],j=0;
bool k[260];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>x;k[x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        in>>x;
        if(k[x])
        {
            j++;
            a[j]=x;
        }
    }
    out<<j<<'\n';
    for(int i=1;i<=j;++i)
    {
        out<<a[i]<<' ';
    }
    return 0;
}
