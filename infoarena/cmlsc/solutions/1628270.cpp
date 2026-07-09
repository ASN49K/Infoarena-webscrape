#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int NMAX = 1025;
int t[NMAX][NMAX];
int n,m;
int a[NMAX];
int b[NMAX];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int d[NMAX];
int u = 0;

int main()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>a[i];
    for(int i=1;i<=n;i++)
        in>>b[i];
    in.close();
    ///
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        if(a[i]==b[j])
        t[i][j] = t[i-1][j-1] + 1;
    else
        t[i][j] = max(t[i-1][j],t[i][j-1]);
    ///
    int i=m,j=n;
    while(i)
    {
        if(a[i]==b[j])
        {
            d[++u] = a[i];
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    out<<t[m][n]<<"\n";
    for(int i=u;i>=1;i--)
        out<<d[i]<<" ";
    out.close();
    return 0;
}
