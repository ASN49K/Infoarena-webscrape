#include <fstream>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

int s1[1024], s2[1024];
int l[1025][1025];
int sol[1024];
int main() {
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n; i++) in >> s1[i];

    for (int i = 0; i < m; i++) in >> s2[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j])
                l[i + 1][j + 1] = l[i][j] + 1;
            else
                l[i + 1][j + 1] = std::max(l[i][j + 1], l[i + 1][j]);
        }
    }

    out << l[n][m] << '\n';
    int i_sol = 0;
    for (int i = n, j = m; l[i][j] != 0;) {
        if (l[i - 1][j] == l[i][j]) {
            i--;
        } else if (l[i][j - 1] == l[i][j]) {
            j--;
        } else if (l[i - 1][j - 1] + 1 == l[i][j]) {
            sol[i_sol++] = s1[i - 1];
            i--, j--;
        }
    }

    for (int i = l[n][m] - 1; i >= 0; i--) {
        out << sol[i] << ' ';
    }
}