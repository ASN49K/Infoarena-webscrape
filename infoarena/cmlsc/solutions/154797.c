#include <stdio.h>
#define MAX 1025

int mat[MAX][MAX];

int main(){
FILE *f=fopen("cmlsc.in","r");
int m,n,len=0;
fscanf(f,"%d",&m);
fscanf(f,"%d",&n);
int i;
for(i=2;i<=m+1;i++) fscanf(f,"%d",&mat[0][i]);
for(i=2;i<=n+1;i++) fscanf(f,"%d",&mat[i][0]);
int j;
FILE *g=fopen("cmlsc.out","w");
for(i=2;i<=n+1;i++)
  for(j=2;j<=m+1;j++)
     if(mat[i][0]==mat[0][j]) {
         mat[i][j]=mat[i-1][j-1]+1;
         len=mat[i][j];     
        }
fprintf(g,"%d ",len);
  fprintf(g,"\n");
for(i=2;i<=n+1;i++)
   for(j=2;j<=m+1;j++)
       if(mat[i][j]>0&&mat[i][j]!=mat[i-1][j+1]){
          fprintf(g,"%d ",mat[i][0]);
          
         }
fprintf(g,"\n");
fclose(g);
return 0;
}
