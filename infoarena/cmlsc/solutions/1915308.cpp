#include <iostream>
#include <fstream>
#define nmax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[nmax], b[nmax];
int d[nmax][nmax];
int sir[nmax], best;

void citire()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        f>>a[i];
    }
    for(int j=1; j<=m; ++j)
    {
        f>>b[j];
    }
}

void dynamic_programming()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
            {
                d[i][j]=1+d[i-1][j-1];
            }
            else
            {
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    for(int i=n, j=m; i; )
    {
        if(a[i]==b[j])
        {
            sir[++best]=a[i];
            --i;
            --j;
        }
        else
        {
            if(d[i][j-1]<d[i-1][j])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
    }
    g<<best<<"\n";
    for(int i=best; i; --i)
    {
        g<<sir[i]<<" ";
    }
}

int main()
{
    citire();
    dynamic_programming();
    return 0;
}
