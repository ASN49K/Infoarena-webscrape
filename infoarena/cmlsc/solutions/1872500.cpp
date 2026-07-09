#include <fstream>
#include <algorithm>
#define NMAX 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n;
int a[NMAX],b[NMAX],c[NMAX][NMAX],sol[NMAX],k;
int main(){
    f>>m>>n;
    int i,j;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(i=1;i<=n;i++)
        f>>b[i];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
    }
    g<<c[m][n]<<'\n';
   for (i = m, j = n; i; )
        if (a[i] == b[j])
            sol[++k] = a[i], --i, --j;
        else if (c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;

    for(i=k;i>=1;i--)
        g<<sol[i]<<' ';
    return 0;
}
