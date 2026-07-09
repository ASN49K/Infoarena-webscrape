//cmlsc
#include<bits/stdc++.h>
#define debug cerr<<"ok";
#define MAXN 1024
using namespace std;

int n,i,j,a[MAXN],b[MAXN],D[MAXN][MAXN],m;
int way[MAXN],cnt=0;

void drum(){

for(i=n,j=m;i>=1,j>=1;){
    if(a[i] == b[j])
        way[++cnt]=a[i], --i,--j;
    else if (D[i-1][j] < D[i][j-1])
            --j;
    else
            --i;
}

for(i=cnt;i>=1;i--)
    printf("%d ",way[i]);

}

int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
     for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

    D[0][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j], D[i][j-1]);

        printf("%d\n",D[n][m]);
        drum();
    return 0;
}
