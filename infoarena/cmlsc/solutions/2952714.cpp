#include <fstream>
#include <cstring>
#include <stack>
#include <cassert>

const int nmax = 1025;
using namespace std;
int v2[nmax][nmax];
pair<int, int> v3[nmax][nmax];

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n1, n2;
    int v[1025], v1[1025];
    ///fin.getline(v + 1, 1000);
    /// fin.getline(v1 + 1, 1000);
    ///fin>>(v+1)>>(v1+1);
    ///n1 = strlen(v + 1);
    /// n2 = strlen(v1 + 1);
    fin >> n1 >> n2;
    for (int i = 1; i <= n1; i++) {
        fin >> v[i];
    }
    for (int i = 1; i <= n2; i++) {
        fin >> v1[i];
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (v[i] == v1[j]) {
                v2[i][j] = v2[i - 1][j - 1] + 1;
                v3[i][j] = {i - 1, j - 1};
            } else {
                if (v2[i - 1][j] > v2[i][j - 1]) {
                    v2[i][j] = v2[i - 1][j];
                    v3[i][j] = {i - 1, j};
                } else {
                    v2[i][j] = v2[i][j - 1];
                    v3[i][j] = {i, j - 1};
                }
            }
        }
    }
    int l = v2[n1][n2];
    fout << l << '\n';
    pair<int, int> poz = {n1, n2};
    stack<int> sol;
    while (l) {
        if (v3[poz.first][poz.second] == make_pair(poz.first - 1, poz.second - 1)) {
            sol.push(v1[poz.second]);
            l--;
            assert(v1[poz.second] == v[poz.first]);
        }
        poz = v3[poz.first][poz.second];
    }
    while (!sol.empty()) {
        fout << sol.top() << " ";
        sol.pop();
    }
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
