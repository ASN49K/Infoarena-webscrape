#include<cstdio>
#define MAX 1024
using namespace std;

int a[MAX+1];
int b[MAX+1];

int d[MAX+1][MAX+1];
int prec_x[MAX+1][MAX+1];
int prec_y[MAX+1][MAX+1];

int main(){
    freopen ("cmlsc.in","r",stdin);
    freopen ("cmlsc.out","w",stdout);
    int n,m,i,j,p,aux;

    scanf ("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        scanf ("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf ("%d",&b[j]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if (d[i-1][j]<d[i][j-1]){
                d[i][j]=d[i][j-1];
                prec_x[i][j]=i;
                prec_y[i][j]=j-1;
            }
            else {
                d[i][j]=d[i-1][j];
                prec_x[i][j]=i-1;
                prec_y[i][j]=j;
            }
            if (a[i]==b[j] &&d[i-1][j-1]+1>d[i][j]){
                d[i][j]=d[i-1][j-1]+1;
                prec_x[i][j]=i-1;
                prec_y[i][j]=j-1;
            }
        }

    printf ("%d\n",d[n][m]);

    p=1;
    i=n;
    j=m;
    while(i>0 &&j>0){
        if (a[i]==b[j]){
            d[0][p]=a[i];
            p++;
        }
        aux=prec_x[i][j];
        j=prec_y[i][j];
        i=aux;
    }

    for(i=p-1;i>0;i--)
        printf ("%d ",d[0][i]);

    return 0;
}
