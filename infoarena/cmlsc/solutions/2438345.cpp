#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1050],b[1050],v[1050][1050],sol[1050],ind;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        in>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    out<<v[n][m]<<'\n';
    int i=n,j=m;
    while(v[i][j]>0)
    {
        if(a[i]==b[j])
        {
            sol[++ind]=a[i];
            i--;j--;
        }
        else
        {
            if(v[i-1][j]>v[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int x=ind;x>=1;x--)
    {
        out<<sol[x]<<' ';
    }
    return 0;
}
