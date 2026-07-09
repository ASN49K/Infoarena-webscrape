#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define file_in "cmlsc.in"
#define file_out "cmlsc.out"

#define nmax (1<<10)+1

int n,m,lmax;
int a[nmax];
int b[nmax];
int sir[nmax];
int d[nmax][nmax];

void citire()
{
    //freopen(file_in,"r",stdin);
    //freopen(file_out,"w",stdout);

    int i;
    scanf("%d %d", &n, &m);
    for (i=1;i<=n;++i)
         scanf("%d", &a[i]);
    for (i=1;i<=m;++i)
         scanf("%d", &b[i]);

}

void solve()
{
    int i,j;

    for (i=1;i<=n;++i)
         for (j=1;j<=m;++j)
              if (a[i]==b[j])
                  d[i][j]=1+d[i-1][j-1];
                  else
                  d[i][j]=max(d[i-1][j],d[i][j-1]);

    for(i=n,j=m;i;)
        if (a[i]==b[j])
        {
            sir[++lmax]=a[i];
            i--;
            j--;
        }
        else
        if (d[i-1][j]>d[i][j-1])
            i--;
        else
        j--;

        printf("%d\n", lmax);
        for (i=lmax;i>=1;--i)
             printf("%d ", sir[i]);

}

int main()
{
    citire();
    solve();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
