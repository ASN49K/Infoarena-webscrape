#include <iostream>
#include <cstdio>
using namespace std;
int a[1030], b[1030], ab[1030][1030],n,m;
void matrice()
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            ab[0][j+1]=b[j];
            ab[i+1][0]=a[i];
        }
    }
}
int umple()
{
    int nr=0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if(ab[i][0]==ab[0][j])
                {ab[i][j]=ab[i][0];nr++;}
        }
        return nr;
}
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(ab[i][j]!=0)
                printf("%d ", ab[i][j]);
    }
}
int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d ", &a[i]);
    for(int i=0; i<m; i++)
        scanf("%d ", &b[i]);
    matrice();
    printf("%d\n", umple()-1);
    afisare();
    return 0;
}
