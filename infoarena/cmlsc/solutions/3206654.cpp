#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <string>
#include <climits>
#include <cstring>

#define LL long long
#define billion 1000000000
const LL mod = 998244353;
const double pi = 3.14159265359;

#define maxn 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[maxn], b[maxn], lcs[maxn][maxn];

void Traceback(int x, int y) {
    if (lcs[x][y] == 0)
        return;

    if (a[x] == b[y]) {
        Traceback(x - 1, y - 1);
        fout << a[x] << " ";
    }
    else {
        if (lcs[x - 1][y] == lcs[x][y])
            Traceback(x - 1, y);
        else
            Traceback(x, y - 1);
    }
}

void ComputeLCS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    fout << lcs[n][m] << "\n";
}

void read() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
}

int main() 
{
    read();
    ComputeLCS();
    Traceback(n, m);
    return 0;
}