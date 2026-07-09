#include <iostream>
#include <fstream>

using namespace std;

ifstream f("siruri.in");
ofstream g("siruri.out");

int x[1025][1025];

int main()
{
    int n,m,i,j,a[1025],b[1025],maxim,k,l,ok,c,d,y[1025];
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                maxim=0;
                for(k=1;k<=i;k++)
                {
                    for(l=1;l<=j;l++)
                        if(x[k][l]>maxim) maxim=x[k][l];
                }
                x[i][j]=maxim+1;
            }
        }
    }
    maxim=0;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(x[i][j]>maxim) maxim=x[i][j];
    }
    g<<maxim;
    g<<'\n';
    c=n;
    d=m;
    for(k=maxim;k>=1;k--)
    {
        ok=0;
        i=c;
        while(i>=1&&ok==0)
        {
            j=d;
            while(j>=1&&ok==0)
            {
                if(x[i][j]==k)
                {
                    ok=1;
                    c=i;
                    d=j;
                    y[k]=a[i];
                }
                j--;
            }
            i--;

        }
    }
    for(i=1;i<=maxim;i++)
        g<<y[i]<<' ';
    return 0;
}
