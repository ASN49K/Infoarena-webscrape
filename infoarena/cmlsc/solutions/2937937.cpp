#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = (1 << 10);

int dp[NMAX + 1][NMAX + 1], a[NMAX + 1], b[NMAX + 1], last[NMAX + 1];

void drum(int x, int y){

    if(x == 0 || y == 0)
        return;

    if(a[x] == b[y])
        drum(x - 1, y - 1);
    else if(dp[x - 1][y] <= dp[x][y - 1])
        drum(x, y - 1);
    else drum(x - 1, y);

    if(a[x] == b[y])
        cout << a[x] << " ";

}

int main(){

    int n = 0, m = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= m; i++)
        cin >> b[i];


    int maxi = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }
    }

    cout << dp[n][m] << "\n";
    drum(n, m);

    return 0;
}
