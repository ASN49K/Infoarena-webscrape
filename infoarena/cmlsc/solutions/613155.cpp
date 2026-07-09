#include <stdio.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int matrice [1030][1030],m,n,a[1030],b[1030];

void initializare ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
}

void citire ()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
}

void prelucrare ()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int diag=MAX(matrice[i-1][j],matrice[i][j-1]);
            if(a[j]==b[i])
                diag=matrice[i][j-1]+1;
            matrice[i][j]=diag;
        }
}

void scriere ()
{
    printf("%d",matrice[n][m]);
}

int main()
{
    initializare();
    citire();
    prelucrare();
    scriere();
    return 0;
}
