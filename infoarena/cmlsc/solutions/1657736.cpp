#include<fstream>
#define maxn 1100

int A[maxn], B[maxn], dp[maxn][maxn], sol[maxn];
int n, m, cnt = 0;

int main() {

    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    in>>n>>m;

    for(int i = 1;i <= n;i++)
        in>>A[i];

    for(int i = 1;i <= m;i++)
        in>>B[i];


    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);


    while(n > 0 && m > 0) {
        if(A[n] == B[m]) {
            sol[cnt++] = A[n];
            n--;
            m--;
        }
        else if(dp[n-1][m] > dp[n][m-1])
            n--;
        else
            m--;
    }

    out<<cnt<<"\n";
    for(int i = cnt - 1 ; i >= 0; i--)
        out<<sol[i]<<" ";

    return 0;
}
