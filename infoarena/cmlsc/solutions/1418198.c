#include <stdio.h>
#include <stdlib.h>
#define MAXN 1024
int mat[MAXN+1][MAXN+1],a[MAXN],b[MAXN],v[MAXN];
int main(){
    FILE*fi,*fout;
    int n,m,i,j,con,max;
    fi=fopen("cmlsc.in" ,"r");
    fout=fopen("cmlsc.out" ,"w");
    fscanf(fi,"%d%d" ,&n,&m);
    for(i=0;i<n;i++)
        fscanf(fi,"%d" ,&a[i]);
    for(i=0;i<m;i++)
        fscanf(fi,"%d" ,&b[i]);
    max=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
             if(a[i-1]==b[j-1])
                 mat[i][j]=mat[i-1][j-1]+1;
             else
                  if(mat[i-1][j]>mat[i][j-1])
                      mat[i][j]=mat[i-1][j];
                  else
                      mat[i][j]=mat[i][j-1];
              if(mat[i][j]>max)
                  max=mat[i][j];
        }
    fprintf(fout,"%d\n" ,max);
    con=0;
    for(i=n;i>0;i--)
        for(j=m;j>0;j--)
            if(mat[i][j]==max&&a[i-1]==b[j-1]){
                max--;
                v[con++]=a[i-1];
            }
    for(i=con-1;i>=0;i--)
        fprintf(fout,"%d " ,v[i]);
    fclose(fi);
    fclose(fout);
    return 0;
}
