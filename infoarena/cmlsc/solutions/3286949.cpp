//dp[i][j] - lungimea celui mai lung subsir comun daca consider doar elem [1, i] din primul sir si elem [1, j] din al doilea sir
//dp[i][j] = max(   dp[i - 1][j - 1] + 1    daca iau a[i] cu b[j]
//                  dp[i][j - 1]            daca iau a[i] cu un b[k], k < j, sau nu il iau deloc                    
//                  dp[i - 1][i]]       )   daca iau b[i] cu un a[k], k < j, sau nu il iau deloc                       

#include <fstream>
#include <vector>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int NMAX = 1024;

int a[NMAX + 1], b[NMAX + 1];
int dp[NMAX + 1][NMAX + 1];

int main() {

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max((dp[i - 1][j - 1] + 1) * (a[i] == b[j]), max(dp[i][j - 1], dp[i - 1][j]));

    cout << dp[n][m] << '\n';

    vector<int> path;

    int ci = n, cj = m;
    bool advance = true;
    while (advance) {

        advance = false;

        if (ci > 1 && dp[ci - 1][cj] == dp[ci][cj]) {
            advance = true;
            ci--;
        }
        else if (cj > 1 && dp[ci][cj - 1] == dp[ci][cj]) {
            advance = true;
            cj--;
        } 
        else if ((ci > 1 || cj > 1) && dp[ci - 1][cj -  1] == dp[ci][cj] - 1) {   //asta trebuie sa fie la sfarsit pt ca se poate indeplini conditia si daca a[i] != b[j]
            path.push_back(a[ci]);
            advance = true;
            ci--, cj--;
        }
    }

    for (vector<int>::reverse_iterator i = path.rbegin(); i != path.rend(); i++)
        cout << *i << ' ';
}