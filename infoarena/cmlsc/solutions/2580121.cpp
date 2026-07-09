#include <cstdio>

const short int N = 1025;

char sol[N], a[N], b[N];
short int dp[N][N], cnt, m, n;

constexpr short int max(short int a, short int b){
    return a>b?a:b;
}

inline void read(){
    scanf("%hi %hi",&n, &m);
    
    for(unsigned short int i = 1; i <= n; ++i)
        scanf("%hi", &a[i]);

    for(unsigned short int i = 1; i <= m; ++i)
        scanf("%hi", &b[i]);
}

int main(){
    freopen("cmlsc.out","w",stdout);
    freopen("cmlsc.in","r",stdin);
    
    read();
    
    for(short int i = 1; i <= n; ++i)
        for(short int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                
    for(short int i=n, j=m; i; )
        if(a[i] == b[j]) --j, sol[++cnt] = a[i--];
            else if(dp[i-1][j] < dp[i][j]) --j;
                else --i;
                
    printf("%hi\n", cnt);
    for(short int i=cnt; i > 0; --i)
        printf("%hi ", sol[i]);
    
    return 0;
}
