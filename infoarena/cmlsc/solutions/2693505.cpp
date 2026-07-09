#include <iostream>
#include <fstream>
using namespace std;
int n,v[2002],i,j,benis[6005],pol[2025],a,ok=1,mini,nr=1,cap,d[1025][1025],m,z,k,maxi;
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>v[i];
    for(i=1; i<=m; i++)
        in>>benis[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v[i]==benis[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                //pol[ok]=v[i];
                //ok++;
            }
            else
            {
                maxi=-1323;
                if(d[i][j-1]>maxi)
                    maxi=d[i][j-1];
                if(d[i-1][j]>maxi)
                    maxi=d[i-1][j];
                d[i][j]=maxi;
            }
        }
    out<<d[n][m]<<'\n';
    for(i=n; i>=1; i--)
        for(j=m; j>=1; j--)
            if(v[i]==benis[j])
            {
                pol[ok]=v[i];
                ok++;
                i--;
                j--;
            }
            else if(d[i][j-1]>d[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
    for(i=ok-1; i>=1; i--)
        out<<pol[i]<<' ';

    return 0;
}
