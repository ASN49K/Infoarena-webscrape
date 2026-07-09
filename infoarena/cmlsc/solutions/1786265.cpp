#include <cstdio>
#define NMAX 1024

using namespace std;

int a[NMAX], b[NMAX], n, m, c[NMAX][NMAX], d[NMAX];

void citire()
{
    scanf("%d %d\n", &n, &m);
    for(int i=0;i<n;i++)
        scanf("%d ", &a[i]);
    scanf("\n");
    for(int j=0;j<m;j++)
        scanf("%d ", &b[j]);
}

int caut(int nr, int x)
{
    int st=0, dr=nr-1, mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(d[mij]==x)
            return 1;
        else
            if(d[mij]<x)
                st=mij+1;
            else
                dr=mij-1;
    }
    return 0;
}

int cond(int i, int j)
{
    if(i==n-1 && j!=m-1)
        return 0;
    return 1;
}

void generare()
{
    int nr=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                if(b[j]==a[i] && !caut(nr, a[i]) && cond(i, j))
                {
                    nr++;
                    d[nr-1]=a[i];
                }
                c[i][j]=nr;
            }
      printf("%d\n", nr);
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
