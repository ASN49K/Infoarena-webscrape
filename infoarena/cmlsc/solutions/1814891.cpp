#include <stdio.h>
int a[1025];
int b[1025];
int sol[1025][1025];
int stiv[1025];
int main(){
  FILE *in,*out;
  in = fopen ("cmlsc.in","r");
  out = fopen ("cmlsc.out","w");
  int n,m,i,j,k;

  fscanf(in,"%d%d",&n,&m);
  for (i=1;i<=n;i++)
    fscanf(in,"%d",&a[i]);
  for (i=1;i<=m;i++)
    fscanf(in,"%d",&b[i]);

  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      if (a[i] == b[j])
        sol[i][j] = sol[i-1][j-1] + 1;
      else
        sol[i][j] = sol[i-1][j] > sol[i][j-1] ? sol[i-1][j] : sol[i][j-1];

  i = n;j = m;
  k = 0;
  while (i > 0){
    if (a[i] == b[j]){
      k ++;
      stiv[k] = a[i];
      i --;j --;
    }
    else if (sol[i-1][j] < sol[i][j-1])
      j --;
    else
      i--;
  }

  fprintf(out,"%d\n",k);
  for (i=k;i>=1;i--)
    fprintf(out,"%d ",stiv[i]);

  fclose (in);
  fclose (out);
  return 0;
}
