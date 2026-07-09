#include <cstdio>
#define MAXN 1024
int d[MAXN+1][MAXN+1],v1[MAXN+1],v2[MAXN+1],v3[MAXN+1];
inline int getmax(int a,int b){
    if(a<b) return b;
    return a;
}
int main(){
    FILE*fi,*fout;
    int i,j,n,m,l;
    fi=fopen("cmlsc.in" ,"r");
    fout=fopen("cmlsc.out" ,"w");
    fscanf(fi,"%d%d" ,&n,&m);
    for(i=1;i<=n;i++)
      fscanf(fi,"%d" ,&v1[i]);
    for(i=1;i<=m;i++)
      fscanf(fi,"%d" ,&v2[i]);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++){
         if(v1[i]==v2[j])
           d[i][j]=d[i-1][j-1]+1;
         else
           d[i][j]=getmax(d[i-1][j],d[i][j-1]);
      }
    fprintf(fout,"%d\n" ,d[n][m]);
    l=d[n][m];
    for(i=n;i>0;i--)
      for(j=m;j>0;j--)
         if(d[i][j]==l&&v1[i]==v2[j]&&l>0){
            v3[l]=v1[i];
            l--;
         }
    for(i=1;i<=d[n][m];i++)
      fprintf(fout,"%d " ,v3[i]);
    fclose(fi);
    fclose(fout);
    return 0;
}
