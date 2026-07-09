#include <stdio.h>
#define DIM 105


int a[DIM][DIM];
int x[DIM];
int y[DIM];
int s[DIM];

int n,m,i,j,nr;

int main(){
  FILE *f = fopen("cmlsc.in","r");
  fscanf(f,"%d %d",&n,&m);
  for (i=1;i<=n;i++)
    fscanf(f,"%d",&x[i]);

  for (i=1;i<=m;i++)
    fscanf(f,"%d",&y[i]);
  fclose(f);

  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      if (x[i]==y[j])
	a[i][j]=a[i-1][j-1]+1;
      else
	if (a[i-1][j]>a[i][j-1])
	  a[i][j]=a[i-1][j];
	else
	  a[i][j]=a[i][j-1];

  i=n;j=m;
  nr=a[n][m];
  while (nr>0)
    if (x[i]==y[j]){
      s[nr]=x[i];
      nr--;
      i--;
      j--;
    } else
      if (a[i-1][j]>a[i][j-1])
	i--;
      else
	j--;

  FILE *g = fopen("cmlsc.out","w");
  fprintf(g,"%d\n",a[n][m]);
  for (i=1;i<=a[n][m];i++)
    fprintf(g,"%d ",s[i]);
  fclose(g);

  return 0;
}