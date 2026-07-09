#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,c[1025],v[1025],z[1025][1025],k=0,st[1025];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(v[i]==c[j])
               z[i][j]=z[i-1][j-1]+1;
            else
                z[i][j]=max(z[i-1][j],z[i][j-1]);
    }
    out<<z[n][m]<<'\n';
    int i=n,j=m;
    while(i!=0 and j!=0)
    {

            if(v[i]==c[j])
            {
              k++;
              st[k]=v[i],i--,j--;
            }
            else
                if(z[i-1][j]<z[i][j-1])
                     j--;
                else
                    i--;
    }
    for(int i=k;i>=1;i--)
        out<<st[i]<<" ";
}
