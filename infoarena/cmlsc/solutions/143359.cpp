#include<stdio.h>
#define N 1030
int v[N][N],a[N],b[N],sol[N];
int max(int a,int b){
    if (a>b)
       return a;
    return b;
}

int main(){
    int n,m,i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (i=1;i<=m;++i)
        scanf("%d",&b[i]);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j)
            v[i][j]=(a[i]==b[j])?(1+v[i-1][j-1]):(max(v[i-1][j],v[i][j-1]));
    for (i=n,j=m;i;)
        if (a[i]==b[j]){
           sol[++sol[0]]=a[i];
           --i;
           --j;
        }
        else 
             if (v[i-1][j]<v[i][j-1])  
                --j;  
        else  
              --i;
    printf("%d\n",sol[0]);
    for (i=sol[0];i>1;--i)
        printf("%d ",sol[i]);
    printf("%d",sol[1]);
    return 0;
}
