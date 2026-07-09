#include <stdio.h>
#include <stdlib.h>

#define NMAX 1024

int v[NMAX+1],v2[NMAX+1];
int d[NMAX+1][NMAX+1]; ///lungimea celui mai lung subsir comun care se termina pe i in v, pe j in v2
int v3[NMAX+1];

int max (int a,int b){
  if(a>b)
    return a;
  return b;
}

int main()
{
  FILE *fin,*fout;
  fin=fopen("cmlsc.in","r");
  fout=fopen("cmlsc.out","w");

  int n,m,i,j,nr=0;
  fscanf(fin,"%d%d",&n,&m);
  for(i=1;i<=n;i++){
    fscanf(fin,"%d",&v[i]);
  }
  for(j=1;j<=m;j++){
    fscanf(fin,"%d",&v2[j]);
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(v[i]==v2[j]){
        d[i][j]=d[i-1][j-1]+1;
      }
      else{
        d[i][j]=max(d[i][j-1],d[i-1][j]);
      }
    }
  }

  fprintf(fout,"%d\n",d[n][m]);

  i=n;
  j=m;
  while(i>0&&j>0){
    if(v[i]==v2[j]){
      v3[nr++]=v[i];
      i--;
      j--;
    }
    else{
      if(d[i-1][j]>d[i][j-1])
        i--;
      else
        j--;
    }
  }
  for(i=nr-1;i>=0;i--){
    fprintf(fout,"%d ",v3[i]);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
