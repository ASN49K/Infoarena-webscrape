#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1025],b[1025],ma[1025][1025],i,j,d[1025],k;
int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(j=1;j<=m;j++)
        in>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                ma[i][j]=1+ma[i-1][j-1];
                else ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
    out<<ma[n][m]<<'\n';
    i=n; j=m; k=0;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            k++;
            d[k]=a[i];
            i--; j--;
        }
        else if(ma[i][j-1]<ma[i-1][j])
            i--;
            else j--;
    }
    for (i=k;i>=1;i--)
        out<<d[i]<<' ';


    in.close();
    out.close();
    return 0;
}
