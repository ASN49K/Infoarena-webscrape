#include <stdio.h>
#include <stdlib.h>
short a[1024],b[1024],mat[1025][1025],v[1024];
int main(){
    FILE*fi,*fout;
    int m,n,i,max,j,lin,col,x;
    fi=fopen("cmlsc.in" ,"r");
    fout=fopen("cmlsc.out" ,"w");
    fscanf(fi,"%d%d" ,&m,&n);
    for(i=0;i<m;i++){
       fscanf(fi,"%hd" ,&a[i]);
       mat[0][i]=0;
    }
    for(i=0;i<n;i++){
       fscanf(fi,"%hd" ,&b[i]);
       mat[i][0]=0;
    }
    max=0;
    for(i=1;i<=n;i++){
       for(j=1;j<=m;j++){
            if(a[j-1]==b[i-1])
               mat[i][j]=mat[i-1][j-1]+(a[j-1]==b[i-1]);
            else
               if(mat[i-1][j]>mat[i][j-1])
                   mat[i][j]=mat[i-1][j];
               else
                   mat[i][j]=mat[i][j-1];
            if(mat[i][j]>max)
                  max=mat[i][j];
       }
    }
    fprintf(fout,"%d\n" ,max);
    x=0;
    for(i=n;i>0;i--)
          for(j=m;j>0;j--){
                if(b[i-1]==a[j-1]&&mat[i][j]==max){
                    max--;
                    v[x++]=b[i-1];
                }
          }
    for(i=x-1;i>=0;i--)
        fprintf(fout,"%hd " ,v[i]);
    fclose(fi);
    fclose(fout);
    return 0;
}
