#include <stdio.h>
#include <stdlib.h>
#define maxim(a, b) ( (a>b) ? a: b )
int v[1025], u[1025], a[1024], ma[1025][1025], l;
int main(){
  int n, m, i, j;
  FILE *fin, *fout;
  fin=fopen("cmlsc.in", "r");
  fout=fopen("cmlsc.out", "w");
  fscanf(fin, "%d%d", &n, &m);
  for(i=1; i<=n; i++)
    fscanf(fin, "%d", &v[i]);
  for(i=1; i<=m; i++)
    fscanf(fin, "%d", &u[i]);
  for(i=1; i<=n; i++)
    for(j=1; j<=m; j++){
      if(v[i]==u[j])
        ma[i][j]=ma[i-1][j-1]+1;
      else ma[i][j]=maxim(ma[i-1][j], ma[i][j-1]);
  }
  for(i=n, j=m; i && j; ){
    if(v[i]==u[j]){
      a[l++]=v[i];
      i--; j--;
    }
    else if(ma[i-1][j]>=ma[i][j-1])
      i--;
    else j--;
  }
  fprintf(fout, "%d\n", l);
  for(i=l-1; i>=0; i--)
    fprintf(fout, "%d ", a[i]);
  fclose(fin);
  fclose(fout);
    return 0;
}
