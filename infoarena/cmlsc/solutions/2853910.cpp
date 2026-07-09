#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v1[1050], v2[1050], sir[1050], maxi;
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> v1[i];
    }

    for (int i = 1; i <= m; ++i) {
        fin >> v2[i];
    }

    int j = 1;
    for (int i = 1; i <= m; ++i) {
        while(j <= n && ((v2[i] == v1[j] && sir[j - 1] != sir[j]) || v2[i] != v1[j])) {
            sir[j] = max(sir[j], sir[j - 1]);
            ++j;
        }

        if (j > n) {
            j = 1;
            continue;
        }

        ++sir[j];
    }

    for (int i = 1; i <= n; ++i) {
        if (sir[i] > maxi)
            maxi = sir[i];
    }

    fout << maxi << '\n';
    j = 1;
    for (int i = 1; i <= n && j <= maxi; ++i) {
        if (sir[i] == j) {
            fout << v1[i] << ' ';
            ++j;
        }
    }
    return 0;
}
