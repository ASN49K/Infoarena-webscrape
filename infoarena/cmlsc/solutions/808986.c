#include<stdio.h>
#define nx 1025
int a[nx],b[nx];
int c[nx][nx];
int max(int x, int y){
if(x>=y)return x; else return y;
}

int main(){
int j,i,n,m,p,z;
        FILE*f=fopen("cmlsc.in","r");
        fscanf(f,"%d %d\n",&n,&m);
        for(i=1;i<=n;i++)fscanf(f,"%d",&a[i]);
        for(i=1;i<=m;i++)fscanf(f,"%d",&b[i]);
        for(i=0;i<=n;i++) c[i][0]=0;
        for(i=0;i<=m;i++) c[0][i]=0;

        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++) if(a[i]==b[j]) {c[i][j]=c[i-1][j-1]+1;}
                             else c[i][j]=max(c[i][j-1],c[i-1][j]);
         FILE*h=fopen("cmlsc.out","w");
         fprintf(h,"%d\n",c[n][m]);
         z=1;
         for(i=1;i<=n;i++)
          for(j=1;j<=m;j++) if(c[i][j]==z) {fprintf(h,"%d ",a[i]); z++;}
fclose(h);
fclose(f);
return 0;
}

