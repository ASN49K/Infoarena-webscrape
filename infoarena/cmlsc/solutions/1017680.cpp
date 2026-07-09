#include <cstdio>
#include <algorithm>

using namespace std;

int a[1025],b[1025],n,m,mat[1025][1025];

void citire()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

}

void subsir()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
               mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
}

void afisare(int i, int j)
{
    if(i<1 || j<1)
       return;
    if(a[i]==b[j])
       {
           afisare(i-1,j-1);
           printf("%d ",a[i]);
       }
    else if(mat[i-1][j]>mat[i][j-1])
       afisare(i-1,j);
    else afisare(i,j-1);

}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    subsir();
    printf("%d\n",mat[n][m]);
    afisare(n,m);
    return 0;
}
