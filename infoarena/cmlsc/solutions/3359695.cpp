
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
vector<int>v1;
vector<int>v2;//stiu ,nume extrem de inspirate
const int NMAX1 = 1025;
int dp[NMAX1][NMAX1];//dp[i][j]= cea mai lunga subsecventa pe care o putem forma daca alegem primele i elemente din primul vector si primele j elemente din al doilea vector
int main()
{
    int n,m;
    fin >> n>>m;
    v1.resize(n);
    v2.resize(m);
    for (int i = 0; i < n; ++i) {
        fin >> v1[i];
        dp[i][0] = 0;
    }
    for (int i = 0; i < m; ++i) {
        fin >> v2[i];
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v1[i-1] == v2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m ;
    vector<int>rez;
    while (j>0 && i>0)
    {
        if (v1[i-1] == v2[j-1]) {
            rez.push_back(v1[i-1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    fout << dp[n][m] << "\n";
    for (auto it = rez.rbegin(); it != rez.rend(); ++it) {
        fout << *it << " ";
    }
    return 0;
}
//=^..^=