#include <fstream>
#include <stack>

using namespace std;
const int NMAX = 1026;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[NMAX], b[NMAX];
int dp[NMAX][NMAX]; ///pt primele a[i] elem si primele b[j] elem, cmlsc
int ult[NMAX][NMAX]; ///pt fiec patratel, salveaza din ce casuta a venit (pt reconstructie)
///0 --> din dp[i - 1][j - 1], 1 --> din dp[i - 1][j], 2--> din dp[i][j - 1]

int dl[] = {-1, -1, 0};
int dc[] = {-1, 0, -1};

stack <int> ans;
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1;  i <= n; i++) ///citire
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if(dp[i][j] == dp[i - 1][j]) ///din care vine
                ult[i][j] = 1;
            else
                ult[i][j] = 2;

            if(a[i] == b[j]) { ///merg --> adaugam la ce avem
                if(dp[i - 1][j - 1] + 1 >= dp[i][j]) { ///merge si >, dar eu vreau max pe diag
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ult[i][j] = 0;
                }
            }
        }
    }
    cout << dp[n][m] << '\n';

    int i = n, j = m, cnt = dp[n][m]; ///reconstructie
    while(cnt) {
        int dir = ult[i][j]; ///de unde a venit
        int lin = i + dl[dir], col = j + dc[dir];
        if(dp[lin][col] + 1 == dp[i][j]) { ///a[i] = b[j], bagam in sol
            ans.push(a[i]);
            cnt--;
        }
        i = lin, j = col;
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}
/*
i - 1, j - 1 --> 0
i - 1, j --> 1
i, j - 1 --> 2
*/