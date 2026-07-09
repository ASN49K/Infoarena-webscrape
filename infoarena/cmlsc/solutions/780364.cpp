#include <cstdio>
#include <algorithm>
using namespace std;
#define Max 1025

int n,m,d[Max][Max],a[Max],b[Max];

void d_prog(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i] == b[j])d[i][j] = 1 + d[i-1][j-1]; else
    d[i][j] = max(d[i-1][j],d[i][j-1]);
}

void rasp(int n,int m){
    if(d[n][m] > 0)
    {
        if(a[n] == b[m])
        {
            rasp(n-1,m-1);
            printf("%d ",a[n]);
        } else
        if(d[n-1][m] > d[n][m-1]) rasp(n-1,m);
        else rasp(n,m-1);
    }
}

int main(){

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);

    d_prog();

    printf("%d\n",d[n][m]);
    rasp(n,m);

    return 0;
}
