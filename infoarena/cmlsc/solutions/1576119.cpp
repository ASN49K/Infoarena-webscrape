#include <cstdio>

#define NMAX 1025
#define max(a,b) a>=b?a:b

using namespace std;

int n,m,nr;
int sol[NMAX];
int a[NMAX],b[NMAX];
int best[NMAX][NMAX];

int main()
{
   freopen("cmlsc.in","r",stdin);
   freopen("cmlsc.out","w",stdout);

   scanf("%d %d\n",&n,&m);

   for (int i=1;i<=n;i++)
     scanf("%d",&a[i]);

   for (int i=1;i<=m;i++)
     scanf("%d",&b[i]);

   for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
       if (a[i]==b[j])best[i][j]=best[i-1][j-1]+1;
       else best[i][j]=max(best[i-1][j],best[i][j-1]);

   printf("%d\n",best[n][m]);

   while (n && m){
     if (a[n]==b[m]){
        sol[++nr]=a[n];
        n--;
        m--;
        continue;
     }
     if (best[n][m]==best[n-1][m])
        n--;
     else
        m--;
   }
   for (;nr;nr--)
     printf("%d ",sol[nr]);

   fclose(stdin);
   fclose(stdout);
}
