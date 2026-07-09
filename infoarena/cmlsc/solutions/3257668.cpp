#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define nmax 1024
int n, m , a[nmax], b[nmax], d[nmax][nmax], sir[nmax],bst;
int main()
{
    int i,j;
    f>>m>>n;
    for( i=1;i<=m;i++)
        f>>a[i];
    for(j=1 ;j<=n;j++)
        f>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                 d[i][j]= 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j],d[i][j-1]);
    i=m;
    j=n;
    while(i>0 || j>0)
    {
        if(a[i]==b[j])
        {
            sir[bst++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]>d[i][j-1] && i>1)
            {
                --i;
            }
            else if(d[i-1][j]<=d[i][j-1] && j>1)
                --j;
            else
            {
                if(i>1)
                    --i;
                else if(j>1)
                    --j;
                else
                    break;
            }
        }
    }
    g<<d[m][n]<<endl;
    for(i=bst-1;i>=0;--i)
        g<<sir[i]<<' ';
    return 0;
}
