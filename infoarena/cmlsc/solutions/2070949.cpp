#include <bits/stdc++.h>
using namespace std;

int a[(1 << 10) + 1], b[(1 << 10) + 1];
int DP[1025][1025];
stack<int> solutie;

class rezolvare{
public :
    void cmlsc(int n, int m)
    {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i] == b[j])
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                else
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
        cout << DP[n][m] << '\n';

        int i = n;
        int j = m;

        while(i > 0 and j > 0) {
            if(a[i] == b[j]) {
                solutie.push(a[i]);
                i--;
                j--;
            }
            else {
                if(DP[i][j - 1] > DP[i - 1][j])
                    j--;
                else
                    i--;
            }
        }

        while(!solutie.empty()) {
            cout << solutie.top() << " ";
            solutie.pop();
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    #endif //ONLINE_JUDGE

    int n, m;
    cin >> n >> m;
    rezolvare x;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> b[i];

    x.cmlsc(n, m);

    return 0;
}
