#include <stdio.h>
#define MAX 1025
int a[MAX],b[MAX],v[MAX][MAX],n,m,sir[MAX];
void citire(){
    freopen("cmlsc.in","r",stdin);
    scanf("%d %d",&n,&m);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d",&b[i]);
    fclose(stdin);
}
int main(){
    citire();
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=v[i][j-1]>v[i-1][j]?v[i][j-1]:v[i-1][j];
        }

     for(i=n,j=m;i;)
         if(a[i]==b[j]){sir[++sir[0]]=a[i];--i;--j;}
         else {
             if(v[i-1][j]<v[i][j-1])
             j--;
             else
             i--;
         }
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",sir[0]);
     for(i=sir[0];i>=1;i--)printf("%d ",sir[i]);



return 0;
}
