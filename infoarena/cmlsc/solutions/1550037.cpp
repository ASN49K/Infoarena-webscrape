#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[1025],b[1025],d[1025][1025];
int ans[1025];

int maxim(int a, int b)
{
    if(a>b) return a;
    else return b;
}

void dp(int a[],int b[],int d[][1025])
{

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if( a[i]==b[j] )
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
        }
    }

    int m1=0;

    for(int i=n;i>=1;)
    {
        for(int j=m;j>=1;)
        {

            if(a[i]==b[j])
            {
                m1++;
                ans[m1]=a[i];
                i--;
                j--;
            }
            else
            {
                if( d[i-1][j] > d[i][j-1] )
                    i--;
                else
                    j--;
            }
        }
    }

    g<<m1<<'\n';

    for(int i=m1;i>=1;i--)
        g<<ans[i]<<' ';
}

int main()
{
    f>>n;
    f>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    dp(a,b,d);
    return 0;
}
