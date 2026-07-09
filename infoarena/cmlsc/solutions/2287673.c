#include<stdio.h>
int v[1025],d,s[1025][1025],i,j,n,m,x[1025],y[1025],k,e;
int main() {
    freopen("cmlsc.in","r",stdin),freopen("cmlsc.out","w",stdout),scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++) {
        s[i][j]=s[i-1][j-1]+(x[i]==y[j]);
        if(s[i][j]<s[i-1][j])
            s[i][j]=s[i-1][j];
        if(s[i][j]<s[i][j-1])
            s[i][j]=s[i][j-1];
    }
    printf("%d\n",s[n][m]),k=s[n][m];
    for(i=n;i;i--)
    for(j=m;j;j--)
    if(s[i][j]==k)
        v[k]=y[j],d=i-1,e=j-1;
    for(i=k-1;i;i--) {
        for(;s[d-1][e]==i;d--);
        for(;s[d][e-1]==i;e--);
        v[i]=x[d],d--,e--;
    }
    for(i=1;i<=k;i++)
        printf("%d ",v[i]);
}
