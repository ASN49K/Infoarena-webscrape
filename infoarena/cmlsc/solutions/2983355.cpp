#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,i,j,a[1025],b[1025],matrice[1025][1025],k,sir[1025];
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i]==b[j])
                matrice[i][j]=1+matrice[i-1][j-1];
               else
                matrice[i][j]=max(matrice[i-1][j],matrice[i][j-1]);
    for (i = m, j = n; i; )
        if(a[i]==b[j])
            {sir[++k]=a[i];
            i--;
            j--;}
        else if(matrice[i-1][j]<matrice[i][j-1])
            --j;
        else
            --i;
    g<<k<<'\n';
    for(i=k;i;--i)
        g<<sir[i]<<" ";
    return 0;
}
