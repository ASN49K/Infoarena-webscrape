#include <iostream>
#include <fstream>
using namespace std;
int n,m,i,v[100000],x,nr=0,a[100000];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>n>>m;
    for(i=1;i<=257;i++)
        v[i]=0;
    for(i=1;i<=n;i++)
        {
            in>>x;
            v[x]++;
        }
    for(i=1;i<=m;i++)
    {
        in>>x;
        if(v[x]!=0)
        {
            nr++;
            v[x]--;
            a[nr]=x;
        }
    }
    out<<nr<<endl;
    for(i=1;i<=nr;i++)
        out<<a[i]<<" ";
}
