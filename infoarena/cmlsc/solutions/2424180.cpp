#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

const int NMAX = 1030;

int a[NMAX],b[NMAX];
int d[NMAX][NMAX];

stack <int> sol;

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int j=1;j<=m;++j)
        scanf("%d",&b[j]);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j){
        d[i][j]=max(d[i-1][j],d[i][j-1]);
        if(a[i]==b[j])
            d[i][j]=max(d[i][j],d[i-1][j-1]+1);
    }
    printf("%d\n",d[n][m]);
    while(n && m){
        if(a[n]==b[m] && d[n-1][m-1]+1==d[n][m]){
            sol.push(a[n]);
            n=n-1;
            m=m-1;
        }else{
            if(d[n][m]==d[n-1][m])
                n=n-1;
            else
                if(d[n][m]==d[n][m-1])
                    m=m-1;
        }
    }
    while(!sol.empty()){
        printf("%d ",sol.top());
        sol.pop();
    }
    return 0;
}
