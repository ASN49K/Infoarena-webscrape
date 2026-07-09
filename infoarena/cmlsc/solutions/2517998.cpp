#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, v[1025], v2[1025], mat[1025][1025], k, show[1025];

int main() {

    in >> n >> m;
    for(int i = 1; i <= n; ++i)
        in >> v[i];
    for(int i = 1; i <= m; ++i)
        in >> v2[i];
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(v[i] == v2[j]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                show[++k] = v[i];
            }
            else {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    out << mat[n][m] << '\n';
    for(int i = 1; i <= k; ++i)
        out << show[i] << ' ';
    return 0;
}