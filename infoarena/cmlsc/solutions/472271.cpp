#include <cstdio>
#define MAXL 1064

int main(){

  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int i, j, X[MAXL], Y[MAXL], C[MAXL][MAXL], M, N, lcs[MAXL], l;

  scanf("%d%d", &M, &N);
  for(i = 1; i <= M; i++)
    scanf("%d", X+i);
  for(i = 1; i <= N; i++)
    scanf("%d", Y+i);

  for(i = 1; i <= M; i++)
    for(j = 1; j <= N; j++)
      if(X[i] == Y[j])
	C[i][j] = 1+C[i-1][j-1];
      else
	C[i][j] = (C[i-1][j] > C[i][j-1])? C[i-1][j]: C[i][j-1];

  i = M; j = N; l = C[i][j];
  while(i && j){
    if(X[i] == Y[j]){
      lcs[l--] = X[i]; i--; j--;
    }
    else if(C[i-1][j] > C[i][j-1])
      i--;
    else
      j--;
  }

  printf("%d\n", (l=C[M][N]));
  for(i = 1; i <= l; i++)
    printf("%d ", lcs[i]);
  printf("\n");
  
  return 0;

}
