#include <cstdio>
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;
int i,j,a[1025],b[1025],c[1025],m,n,x=0;
int d[1025][1025];
int main()
{
   freopen("cmlsc.in", "r", stdin);
   freopen("cmlsc.out", "w", stdout);
   scanf("%d %d",&m,&n);
   for(i=0;i<=n;i++)
    d[0][i]=0;
   for(i=0;i<=m;i++)
    d[i][0]=0;
   for(i=1;i<=m;i++)
    scanf("%d", &a[i]);
   for(i=1;i<=n;i++)
    scanf("%d", &b[i]);

   for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = maxim(d[i-1][j], d[i][j-1]);
  for (i = m, j = n; i; )
        if (a[i] == b[j])
          //   c[++x] = a[i], i--, j--;
           {c[++x] = a[i]; i--; j--;

           }
        else if (d[i-1][j] < d[i][j-1])
            j--;
        else
            i--;
printf("%d\n",d[m][n]);
for(i=x;i>=1;i--)
    printf("%d ",c[i]);
}
