#include <stdio.h>
int n,m,a[1025],b[1025],c[1025][1025];

inline int max(int a,int b){ return a>b?a:b; }

void great(){
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])c[i][j]=1+c[i-1][j-1]; else
    c[i][j]=max(c[i][j-1],c[i-1][j]); }

void common(int i,int j){
    if(c[i][j]>0)
    if(a[i]==b[j]){
        common(i-1,j-1);
        printf("%d ",a[i]); } else {
    if(c[i][j-1]>c[i-1][j])common(i,j-1); else common(i-1,j); }
}

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    great();
    printf("%d\n",c[n][m]);
    common(n,m);
}
