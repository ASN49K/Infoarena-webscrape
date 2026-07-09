#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int c[1025][1025];
int main()
{
    int n,m,v1[1025],v2[1025],s[1025],i,j,k;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>v1[i];
    }
    for(i=1;i<=m;i++)
    {
        f>>v2[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    g<<c[n][m]<<"\n";
    i=n;
    j=m;
    k=c[n][m];
    while((j!=0)&&(i!=0))
    {
        if(v1[i]==v2[j])
        {
            s[k]=v1[i];
            k--;
            i--;
            j--;
        }
        else if(c[i-1][j]<c[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    for(i=1;i<=c[n][m];i++)
    {
        g<<s[i]<<" ";
    }
    return 0;
}
