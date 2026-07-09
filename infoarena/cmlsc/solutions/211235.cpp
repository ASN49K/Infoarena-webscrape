#include<stdio.h>
int n,m,a[1025],b[1025],c[1025][1025],s[1025];
void solve(){
    int i,j,k=0;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i)
        scanf("%d",&a[i]);
    for(i=1; i<=m; ++i)
        scanf("%d",&b[i]);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else    
                c[i][j]=c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
    for(i=n,j=m; i,j; ){
        if(a[i]==b[j]){
            s[++k]=a[i];
            --i;
            --j;}
        else if(c[i-1][j]<c[i][j-1])
            --j;
        else
            --i;}
    printf("%d\n",k);
    for(i=k; i; --i)
        printf("%d ",s[i]);}
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    solve();
    return 0;}  
