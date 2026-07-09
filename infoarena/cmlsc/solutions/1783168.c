#include <stdio.h>
#include <stdlib.h>
#define MAX 1025
int a[MAX], b[MAX], mat[MAX][MAX], dir[MAX][MAX];

void printCMLSC(FILE *fout, int i, int j){
  if(i*j>0)
    if(dir[i][j]==2){
      printCMLSC(fout, i-1, j-1);
      fprintf(fout, "%d ", a[i]);
    } else if(dir[i][j]==1)
        printCMLSC(fout, i-1, j);
      else
        printCMLSC(fout, i, j-1);
}

int main()
{
    FILE *fin, *fout;
    int m, n, i, j;
    fin=fopen("cmlsc.in", "r");
    fscanf(fin, "%d%d", &m, &n);
    for(i=1; i<=m; i++)
      fscanf(fin, "%d", &a[i]);
    for(i=1; i<=n; i++)
      fscanf(fin, "%d", &b[i]);
    fclose(fin);
    for(i=1; i<=m; i++)
      for(j=1; j<=n; j++)
        if(a[i]==b[j]){
          mat[i][j]=mat[i-1][j-1]+1;
          dir[i][j]=2;
        } else if(mat[i-1][j]>mat[i][j-1]){
            mat[i][j]=mat[i-1][j];
            dir[i][j]=1;
        } else{
            mat[i][j]=mat[i][j-1];
            dir[i][j]=3;
        }
    fout=fopen("cmlsc.out", "w");
    fprintf(fout, "%d\n", mat[m][n]);
    printCMLSC(fout, m, n);
    fprintf(fout, "\n");
    fclose(fout);
    return 0;
}
