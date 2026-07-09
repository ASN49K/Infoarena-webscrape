#include <stdio.h>
#include <stdlib.h>

int x[1025], y[1025], mat[1025][1025], rez[1024];

inline int maxim(int a, int b){
  if(a>b)
    return a;
  return b;
}

int main()
{
  int n, m, i , j, max, pozi, pozj, z;
  FILE *fi=fopen("cmlsc.in", "r"), *fo=fopen("cmlsc.out", "w");
  fscanf(fi, "%d%d", &n, &m);
  for(i=1;i<=n;i++)
    fscanf(fi, "%d", &x[i]);
  for(i=1;i<=m;i++)
    fscanf(fi, "%d", &y[i]);
  max=0;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(x[i]==y[j])
        mat[i][j]=mat[i-1][j-1]+1;
      else
        mat[i][j]=maxim(mat[i-1][j],mat[i][j-1]);
      if(mat[i][j]>max){
        max=mat[i][j];
        pozi=i;
        pozj=j;
      }
    }
  }
  z=0;
  i=pozi;
  j=pozj;
  while(mat[i][j]!=0){
    do{
      i--;
    }while(mat[i][j]==mat[i+1][j]);
    i++;
    while(mat[i][j]==mat[i][j-1])
      j--;
    rez[z]=y[j];
    j--;
    i--;
    z++;
  }
  fprintf(fo, "%d\n", max);
  for(z=z-1;z>=0;z--)
    fprintf(fo, "%d ", rez[z]);
  return 0;
}

