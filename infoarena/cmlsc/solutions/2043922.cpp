#include <fstream>
using namespace std;
ifstream f("cmslc.in");
ofstream g("cmslc.out");
int m,n,a[1024],b[1024],d[1024][1024],s[1024],k,i,j;
int main()
{
    f>>m>>n;
    for(i=1; i<=m; i++)
        f>>a[i];
    for(i=1; i<=n; i++)
        f>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
            else if(d[i-1][j]>d[i][j-1])
            d[i][j]=d[i-1][j];
            else
            d[i][j]=d[i][j-1];
        }
    g<<d[m][n]<<'\n';
    i=m;
    j=n;
    k=0;
    while(d[i][j])
        if(a[i]==b[j])
        {
            k++;
            s[k]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1]) i--;
        else j--;
    for(i=k; i>0; i--)
        g<<s[i]<<" ";
    return 0;
}
