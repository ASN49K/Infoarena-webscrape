#include <fstream>
#include <iostream>

using namespace std;

int n,m,a[1025],b[1025],c[1025][1025],d[1025],k=0;

int main()
{

    ifstream mama("cmlsc.in");
    ofstream tata("cmlsc.out");

    int i,j;

    mama>>n>>m;
    for(i=1;i<=n;i++)
        mama>>a[i];
    for(i=1;i<=m;i++)
        mama>>b[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
                if(a[i]==b[j])  c[i][j]=c[i-1][j-1]+1;
            }
    }
    tata<<c[n][m]<<'\n';
    i=n; j=m;
    while(i>0 and j>0)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--; j--;
        }
            else
        if(c[i-1][j]>c[i][j-1]) i--;
            else j--;
    }
    for(i=k;i>0;i--)
        tata<<d[i]<<" ";
    return 0;
}
