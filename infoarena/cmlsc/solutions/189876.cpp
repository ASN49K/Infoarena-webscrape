#include<stdio.h>
#include<iostream.h>

#define NMmax 1024

int mat[NMmax+1][NMmax+1];

int inline MAX(int x, int y) { return (x>y) ? x:y; }

int main()
{
  freopen("cmlsc","r",stdin);
  freopen("cmlsc","w",stdout);

  int n,m,i,j,nstiva=0;   int a[NMmax+1],b[NMmax+1], stiva[NMmax+1];

  scanf("%d %d", &n, &m);

  for(i=1; i<=n; i++)  scanf("%d", &a[i]);
  for(i=1; i<=m; i++)  scanf("%d", &b[i]);

  for(i=1; i<=n; i++)
  for(j=1; j<=m; j++) if(a[i]==b[j])  mat[i][j]+= mat[i-1][j-1]+1;
		      else            mat[i][j]+= MAX(mat[i-1][j],mat[i][j-1]);

  for(i=n,j=m; j && i;)

    if(a[i]==b[j])  { stiva[++nstiva]= a[i]; i--; j--; }

    else
		    if(mat[i-1][j] < mat[i][j-1])  j--;
		    else i--;


  printf("%d\n", mat[n][m]);

  for(i=nstiva; i; i--) printf("%d ", stiva[i]);

  return 0;

}