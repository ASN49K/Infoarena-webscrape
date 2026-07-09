#include <cstdio>
#define NMAX 1024

using namespace std;

int a[NMAX], b[NMAX], n, m, c[NMAX][NMAX];

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
    int nr=0, d[10000];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                if(b[j]==a[i])
                {
                       nr++;
                       d[nr-1]=b[j];
                }
                c[i][j]=nr;
            }
      printf("%d\n", c[n-1][m-1]);
      for(int i=0;i<nr;i++)
         printf("%d ", d[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    citire();
    generare();
    return 0;
}
