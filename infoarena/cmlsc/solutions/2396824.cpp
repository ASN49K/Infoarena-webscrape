#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

int x[MAXN], y[MAXN];
int l[MAXN][MAXN];
int sol[MAXN];
int main(){
  FILE*fin=fopen("cmlsc.in", "r");
  FILE*fout=fopen("cmlsc.out", "w");
  int n, m, i, j;
  char c;
  fscanf(fin, "%d%d", &n, &m);
  for(i=1; i<=n; i++)
    fscanf(fin, "%d", &x[i]);
  for(i=1; i<=m;i++)
    fscanf(fin, "%d", &y[i]);
  for(i=1; i<=n; i++)
    for(j=1; j<=m; j++){
      if(x[i]==y[j])
        l[i][j]=1+l[i-1][j-1];
      else
        l[i][j]=max(l[i-1][j], l[i][j-1]);
    }
  i=n; j=m;
  int k=0;
  while(i>0 && j>0){
    if(x[i]==y[j]){
      k++;
      sol[k]=x[i];
      i--;
      j--;
    }
    else{
      if(l[i-1][j]>l[i][j-1])
        i--;
      else
        j--;
    }
  }
  fprintf(fout, "%d\n", l[n][m]);
  for(i=l[n][m]; i>0; i--)
    fprintf(fout, "%d ", sol[i]);
  return 0;
}
