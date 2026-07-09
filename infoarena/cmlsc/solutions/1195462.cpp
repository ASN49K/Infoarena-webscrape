#include <stdio.h>

int d[1024][1024],i,j,n,m,a[1024],b[1024];
int max(int a, int b){
    if (a>b) return a;
    else return b;
}
void Afis(int i, int j){

    if (d[i][j]>0){
        if (a[i]==b[j]){
            Afis(i-1,j-1);
            printf("%d ",a[i]);
        }
        else if (d[i][j]=d[i-1][j]) Afis(i-1,j);
        else Afis(i,j-1);

    }
}
int main(){


    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&m,&n);

    for (i=1;i<=m;i++) scanf("%d",&a[i]);

    for (i=1;i<=n;i++) scanf ("%d",&b[i]);

    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++) if (a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
                   else d[i][j]=max(d[i-1][j],d[i][j-1]);

    printf("%d\n",d[m][n]);

    Afis(m,n);
    return 0;
}
