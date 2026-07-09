#include <bits/stdc++.h>
using namespace std;

int mx[1050][1050];
int  a[1050],
     b[1050];

int main(void) {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n, m, ans=0;

    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%c",&a[i]);
    for(int i=1; i<=m; ++i)
        scanf("%c",&b[i]);

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            mx[i][j]=int(a[i]==b[j]);

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(mx[i][j])
                mx[i][j]+=mx[i-1][j-1];
            else
                mx[i][j] =max(mx[i-1][j], mx[i][j-1]);
            ans = max(ans, mx[i][j]);
        }
    }

    printf("%d\n",ans);
    return 0;
}
