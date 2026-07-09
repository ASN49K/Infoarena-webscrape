#include <iostream>
#include <cstdio>
#define N 1025
#define max(a, b) a>b?a:b

using namespace std;

int n, m, a[N], b[N], d[N][N], sol[N];

void citire()
{
    scanf("%d %d\n", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d ", &a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d ", &b[i]);
}

void parcurgere()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
}

void solutie()
{
    int i=n, j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            sol[++sol[0]]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    }
}

void afisare()
{
    printf("%d\n", sol[0]);
    for(int i=sol[0];i>0;i--)
        printf("%d ", sol[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    parcurgere();
    solutie();
    afisare();
    return 0;
}
