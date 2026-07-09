#include <cstdio>
#include <vector>
#include <list>
using namespace std;

vector<int> a, b;
list<int> res;
auto fin = fopen("cmlsc.in", "r");
auto fout = fopen("cmlsc.out", "w");

void input() {
    int lena, lenb, el;
    fscanf(fin, "%d %d", &lena, &lenb);
    a.reserve(lena);
    b.reserve(lenb);
    while (lena--) {
        fscanf(fin, "%d", &el);
        a.push_back(el);
    }
    while (lenb--) {
        fscanf(fin, "%d", &el);
        b.push_back(el); 
    }
}

void output() {
    fprintf(fout, "%d\n", res.size());
    for (auto i = res.begin(); i != res.end(); ++i)
        fprintf(fout, "%d ", *i);
    fprintf(fout, "\n");
}

void solve() {
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    auto i = 0u, j = 0u;
    for (i = 0u; i <= a.size(); ++i)
        for (j = 0u; j <= b.size(); ++j)
            if (i == 0u || j == 0u)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    --i; --j;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res.push_front(a[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    // for (auto i = 0u; i <= a.size(); ++i, printf("\n"))
    //     for (auto j = 0u; j <= b.size(); ++j)
    //         printf("%3d ", dp[i][j]);
    // printf("\n");
}

int main() {
    input();
    solve();
    output();
    return 0;
}