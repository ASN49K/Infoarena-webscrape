#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025],b[1025],n,m,mat[1025][1025],c[1025],o;

int main(){
    int i,j;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];

    for(i=1; i<=n; i++)
    for(j=1; j<=m; j++)
    if(a[i]==b[j])
    mat[i][j]=1+mat[i-1][j-1];
    else
        mat[i][j]=max(mat[i-1][j], mat[i][j-1]);

    i=n;
    j=m;
    while(i)
    if(a[i]==b[j])
        c[++o]=a[i--],j--;
    else
        if(mat[i-1][j]<mat[i][j-1])
        j--;
    else
        i--;

    g<<mat[n][m]<<"\n";
    for(i=o;i;i--)
    g<<c[i]<<" ";
    return 0;
}
