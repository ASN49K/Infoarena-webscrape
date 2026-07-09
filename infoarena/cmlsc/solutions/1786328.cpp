#include <cstdio>
#define NMAX 1024

using namespace std;

int a[NMAX], b[NMAX], n, m, d[NMAX][NMAX], c[NMAX], nr;

void citire()
{
    scanf("%d %d\n", &n, &m);
    for(int i=0;i<n;i++)
        scanf("%d ", &a[i]);
    scanf("\n");
    for(int j=0;j<m;j++)
        scanf("%d ", &b[j]);
}

void generare()
{
    int nr=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
               nr++;
            d[i][j]=nr;
        }
}

void solutie()
{
    for(int i=n-1, j=m-1;i>=0;)
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
