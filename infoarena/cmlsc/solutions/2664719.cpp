#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int lMax = 1025;

int N, M;
int n[lMax], m[lMax], dp[lMax][lMax];

void read(){
    fin >> N >> M;

    for(int i = 1; i <= N; i++)
        fin >> n[i];

    for(int j = 1; j <= M; j++)
        fin >> m[j];
}

void solve(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(n[i] == m[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    /**for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            fout << dp[i][j] << " ";
        fout << "\n";
    }*/
}

void printAns(){
    fout << dp[N][M] << "\n";

    int i = N, j = M, idx = 0;
    int ans[lMax];

    while(i >= 1 && j >= 1){
        if(n[i] == m[j]){
            ans[++idx] = n[i];
            i--;
            j--;
        } else if(dp[i - 1][j] < dp[i][j - 1]){
            j--;
        } else
            i--;
    }

    for(int i = idx; i >= 1; i--)
        fout << ans[i] << " ";
}

int main()
{
    read();
    solve();
    printAns();

    return 0;
}
