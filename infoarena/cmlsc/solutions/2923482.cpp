#include <bits/stdc++.h>
#define INFILE "cmlsc.in"
#define OUTFILE "cmlsc.out"
#define DIM 1030

using namespace std;

ifstream f(INFILE);
ofstream g(OUTFILE);

struct PathCoordinates {
    int x;
    int y;
}solPath[DIM][DIM];

bool isValid(PathCoordinates path) {
    if (path.x >= 1 && path.y >= 1)
        return true;
    return false;
}

int n, m;
short int v1[DIM], v2[DIM], dp[DIM][DIM];
vector <int> solution;

int main() {

    f >> n >> m;

    for (int i = 1; i <= n; i++) {
        f >> v1[i];
    }

    for (int i= 1; i <= m; i++) {
        f >> v2[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                if (dp[i][j - 1] > dp[i][j + 1]) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    solPath[i][j] = {i, j - 1};
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                    solPath[i][j] = {i - 1, j};
                }
            } else {
                dp[i][j] = dp[i - 1][j - 1];
                solPath[i][j] = {i - 1, j - 1};
            }
        }
    }

    PathCoordinates path = {n, m};
    while (isValid(path)) {
        if (dp[path.x][path.y] - dp[solPath[path.x][path.y].x][solPath[path.x][path.y].y] == 1) {
            solution.push_back(v1[path.x]);
            path = solPath[path.x][path.y];
        } else {
            path = solPath[path.x][path.y];
        }
    }

    g << dp[n][m] << "\n";

    reverse(solution.begin(), solution.end());
    for (auto k: solution) {
        g << k << " ";
    }

    return 0;

}
