#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1030;

int n,m,a[N],b[N],d[N][N],sol[N],k=0;


int main()
{
    int i,j;
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(j=1; j<=m; j++)
        in>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    i=n;
    j=m;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]< d[i][j-1])
                j--;
            else
                i--;

        }
    }
    out<<k<<'\n';
    for(i=k; i>=1; i--)
        out<<sol[i]<<" ";
    return 0;
}
