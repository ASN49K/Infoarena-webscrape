#include <fstream>
#define SIZE 1025
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
int m, n;
int a[SIZE], b[SIZE], dp[SIZE][SIZE], res[SIZE];
int main()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        fin >> b[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else{
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int k = 0;
    for(int i = m, j = n; i; ){
        if(a[i] == b[j])
            res[++k] = a[i], i --, j --;
        else if(dp[i - 1][j] < dp[i][j - 1]){
            --j;
        }
        else{
            --i;
        }
    }
    for(int i = k; i >= 1; i--)
        fout << res[i] << " ";
    return 0;
}
