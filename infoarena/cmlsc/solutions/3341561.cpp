#include <fstream>
#include <algorithm>

const int NMAX = 1024;
const int MMAX = 1024;

u_int8_t a[NMAX + 1], b[MMAX + 1];
u_int16_t d[NMAX + 1][MMAX + 1];

int main() {
    std::ifstream fin("grader_test2.in");
    std::ofstream fout("cmlsc.out");

    int x;
    u_int16_t n, m, i, j;
    fin >> n >> m;

    for(i = 1; i <= n; ++ i) {
        fin >> x;
        a[n - i + 1] = static_cast<u_int8_t>(x);
    }
    for(i = 1; i <= m; ++ i) {
        fin >> x;
        b[m - i + 1] = static_cast<u_int8_t>(x);
    }

    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            if(a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = std::max(d[i - 1][j], d[i][j - 1]); 
            }
        }
    } 

    fout << d[n][m] << "\n";

    i = n;
    j = m;
    while(i > 0 && j > 0) {
        if(a[i] == b[j]) {
            fout << static_cast<int>(a[i]) << " ";
            -- i;
            -- j;
        } else {
            if(d[i][j] == d[i - 1][j]) {
                -- i;
            } else {
                -- j;
            }
        }
    }

    return 0;
}