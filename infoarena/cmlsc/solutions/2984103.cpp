#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int MAX=1024;
unsigned a[MAX], n, b[MAX], m, L[MAX][MAX], R[MAX], r;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
            if(a[i]==a[j])
            L[i][j]=1+L[i-1][j-1];
        else
            L[i][j]=max(L[i][j-1], L[i-1][j]);
    }
    int i=n, j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            R[++r]=a[i];
            i--;
            j--;
        }
        else
            if(L[i][j-1]<L[i-1][j])
            i--;
        else
            j--;
    }
    g<<r<<'\n';
    for(int i=r; i>0; i--)
        g<<R[i]<<' ';
}
