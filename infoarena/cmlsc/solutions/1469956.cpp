#include <cstdio>
#define nmx 1030
using namespace std;

int n1, n2;
int v1[nmx], v2[nmx];
int dp[nmx][nmx];

inline int max(const int val1, const int val2){
    return val1 > val2 ? val1 : val2;
}

void citire(){
    scanf("%d %d", &n1, &n2);
    for(int i = 1; i <= n1; ++i)
        scanf("%d", &v1[i]);
    for(int i = 1; i <= n2; ++i)
        scanf("%d", &v2[i]);
}

void dinamica(){
    for(int i = 1; i <= n1; ++i)
        for(int j = 1; j <= n2; ++j)
            if(v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
}

void afish(const int i1, const int i2){
    if(not i1 || not i2)
        return;
    if(dp[i1][i2] == dp[i1-1][i2-1] + 1){
        afish(i1-1,i2-1);
        printf("%d ", v1[i1]);
    }
    else if(dp[i1][i2-1] > dp[i1-1][i2])
        afish(i1,i2-1);
    else
        afish(i1-1,i2);
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire();
    dinamica();
    printf("%d\n", dp[n1][n2]);
    afish(n1,n2);
    return 0;
}
