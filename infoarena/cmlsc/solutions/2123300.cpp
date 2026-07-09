#include <iostream>
#include <fstream>
#define DN 1025
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[DN], b[DN], c[DN], l[DN][DN], k, ct;

void construire(int i, int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            construire(i-1, j-1);
            k++;
            c[k]=a[i];
        }
        else
        {
            if(l[i-1][j]>l[i][j-1])
                construire(i-1, j);
            else construire(i, j-1);
        }
    }
}
int main()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
        f>>a[i];
    for(int i=1; i<=n; i++)
        f>>b[i];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])
                l[i][j]=l[i-1][j-1]+1;
            else l[i][j]=max(l[i-1][j], l[i][j-1]);
    //construire(m, n);
    g<<l[m][n]<<'\n';
    k=l[m][n];
    while(m && n)
    {
        if(a[m]==b[n])
        {
            c[k-ct]=a[m];
            m--;
            n--;
            ct++;
        }
        else if(l[m-1][n]>l[m][n-1])
            m--;
        else n--;
    }
    for(int i=1; i<=k; i++)
        g<<c[i]<<" ";
    return 0;
}
