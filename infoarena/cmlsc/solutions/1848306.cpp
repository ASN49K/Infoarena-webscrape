#include<stdio.h>
int a[1025],b[1025],d[1025][1025],v[1025];;
int maxim ( int a , int b){
    if(a>b)
        return a;
    return b;
}
int main(){
    int n,m,i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int k=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]){
                k++;
                v[k]=a[i];
                d[i][j]=1+d[i-1][j-1];
            }
            else
                d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    printf("%d\n",d[n][m]);
    for(i=1;i<=k;i++)
        printf("%d ",v[i]);
    return 0;
}
