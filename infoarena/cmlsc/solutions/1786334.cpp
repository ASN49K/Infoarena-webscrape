#include <cstdio>
#define NMAX 1024

using namespace std;

int a[NMAX], b[NMAX], n, m, d[NMAX][NMAX], c[NMAX], nr;

void citire()
{
    scanf("%d %d\n", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d ", &a[i]);
    scanf("\n");
    for(int j=1;j<=m;j++)
        scanf("%d ", &b[j]);
}

void generare()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                {
                    if(d[i-1][j]>d[i][j-1])
                        d[i][j]=d[i-1][j];
                    else
                        d[i][j]=d[i][j-1];
                }
}

void solutie()
{
    for(int i=n, j=m;i>0;)
        if(a[i]==b[j])
        {
            c[nr++]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
}

void afisare()
{
    printf("%d\n", nr);
    for(int i=nr-1;i>=0;i--)
         printf("%d ", c[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    citire();
    generare();
    solutie();
    afisare();
    return 0;
}
