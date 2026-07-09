#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1025],b[1025],v[1025][1025],c[1025],i,j,x;



int main(){
    f>>m>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (i=1;i<=n;i++)
        f>>b[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        if (a[i]==b[j])
            v[i][j]=v[i-1][j-1]+1;
        else
            v[i][j]=max(v[i-1][j],v[i][j-1]);


    i=m;
    j=n;
    while (i>=1 && j>=1)
        if (a[i]==b[j])
            {c[++x]=a[i];i--;j--;}
        else
            if
                (v[i-1][j]==v[i][j])i--;
            else
                j--;
    g<<x<<'\n';
    for (i=x;i>=1;i--)
        g<<c[i]<<" ";
    return 0;}
