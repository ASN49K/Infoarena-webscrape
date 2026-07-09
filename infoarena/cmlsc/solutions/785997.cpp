
#include <iostream>
#include <fstream>
#include <vector>

#define _MAX_N 1025

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

int lsc[_MAX_N][_MAX_N];
int v1[_MAX_N], v2[_MAX_N];
int n, m;

void read_data()
{
    f >> n >> m;

    for (int i = 1; i <= n; ++i) {
        f >> v1[i];
    }

    for (int i = 1; i <= m; ++i) {
        f >> v2[i];
    }
}

void build_lsc()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (v1[i] == v2[j]) {
                lsc[i][j] = lsc[i - 1][j - 1] + 1;
            }
            else {
                lsc[i][j] = std::max(lsc[i - 1][j], lsc[i][j - 1]);
            }
        }
    }
}

void write_solution()
{
    g << lsc[n][m] << "\n";

    std::vector<int> sol;

    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (v1[i] == v2[j]) {
            sol.push_back(v1[i]);
            i--; j--;
        }
        else {
            if (lsc[i - 1][j] > lsc[i][j -1]) {
                i--;
            }
            else {
                j --;
            }
        }
    }

    for (int i = sol.size() - 1; i >= 0; --i) {
        g << sol[i] << " ";
    }
    g << "\n";
}

int main()
{
    read_data();
    build_lsc();
    write_solution();

    return 0;
}
