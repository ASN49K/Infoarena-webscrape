#include <stdio.h>

int d[1030][1030],i,j,n,m,a[1030],b[1030];
int max(int a, int b){
    if (a>b) return a;
    else return b;
}
void Afis(int k, int h){

    if (d[k][h]>0){
        if (a[k]==b[h]){
            Afis(k-1,h-1);
            printf("%d ",a[k]);
        }
        else if (d[k][h]==d[k-1][h]) Afis(k-1,h);
        else Afis(k,h-1);

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
