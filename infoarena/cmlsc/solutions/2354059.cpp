#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX=1025;

int v1[NMAX];
int v2[NMAX];
int d[NMAX][NMAX];

void dp(int n1,int n2){
    for(int i=1;i<=n1;++i)
    for(int j=1;j<=n2;++j){
        d[i][j]=max(d[i][j-1],d[i-1][j]);
        if(v1[i]==v2[j])
            d[i][j]=max(d[i][j],d[i-1][j-1]+1);
    }
}

int cnt=0;
int sol[NMAX];

void recons(int n,int n1,int n2){
    while(n){
        if(d[n1][n2]==d[n1-1][n2-1]+1 && v1[n1]==v2[n2]){
            sol[++cnt]=v1[n1];
            n--;
            n1--;
            n2--;
        }
        else
            if(d[n1][n2]==d[n1-1][n2])
                n1--;
            else
                n2--;
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    for(int i=1;i<=n1;++i)
        scanf("%d",&v1[i]);
    for(int i=1;i<=n2;++i)
        scanf("%d",&v2[i]);

    dp(n1,n2);
    int n=d[n1][n2];

    printf("%d\n",d[n1][n2]);

    recons(n,n1,n2);
    for(int i=cnt;i>=1;--i)
        printf("%d ",sol[i]);

    return 0;
}
