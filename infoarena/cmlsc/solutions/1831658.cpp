#include <iostream>
#include <fstream>
#define N 1150

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[N],b[N],m,n,d[N][N],sir[N],best;
int main()
{
    int i,j;
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
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
        /*for(i=n,j=m;i;)
        {
            if(a[i]==b[j])
            {
                sir[++best]=a[i];
                --i;
                --j;
            }
            else
                if(d[i-1][j]<d[i][j-1])
                --j;
            else
                --i;
        }*/
        for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
            if(d[i][j]!=0)
            {
                if(a[i]==b[j])
                {
                    sir[++best]=a[i];
                }
            }
        }
        g<<best<<endl;
        for(i=best;i>=1;i--)
            g<<sir[i]<<' ';
        return 0;
}

