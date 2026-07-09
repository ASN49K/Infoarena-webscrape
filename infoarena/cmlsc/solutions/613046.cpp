#include <cstdio>
#include <algorithm>
#define LMAX 1030

using namespace std;

FILE *fin=freopen("cmlsc.in","r",stdin);
FILE *fout=freopen("cmlsc.out","w",stdout);

int a[LMAX],b[LMAX],n,m;
int M[LMAX][LMAX];

void citire()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
}

void initializare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[j]==b[i])
                M[i][j]=M[i-1][j-1]+1;
            else
                M[i][j]=max(M[i][j-1],M[i-1][j]);
}

void afisare(int x, int y)
{
    if(x*y<0)
        return ;
    if(M[x-1][y-1]==M[x][y]-1)
    {
        afisare(x-1,y-1);
        printf("%d ",a[y]);
        return;
    }
    if(M[x-1][y]>M[x][y-1])
        afisare(x-1,y);
    else
        afisare(x,y-1);
}

int main()
{
    citire();
    initializare();
    printf("%d\n",M[n][m]);
    afisare(n,m);
    return 0;
}
