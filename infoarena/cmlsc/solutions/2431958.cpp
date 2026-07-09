#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <iterator>
using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int M, N;
    fin >> M >> N;
    assert(1 <= M && M <= 1024 && 1 <= N && N <= 1024);
    vector<int> a(M + 1), b(N + 1), solution;
    vector<vector<int>> c(M + 1, vector<int>(N + 1));

    for (int i = 1; i <= M; ++i) {
        fin >> a[i];
    }

    for (int i = 1; i <= N; ++i) {
        fin >> b[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (a[i] == b[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    int i = M, j = N;
    while (i && j) {
        if (a[i] == b[j]) {
            solution.push_back(a[i]);
            --i;
            --j;
        } else if (c[i - 1][j] < c[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }

    fout << solution.size() << '\n';
    for (vector<int>::reverse_iterator it = solution.rbegin(); it != solution.rend(); ++it) {
        fout << *it << " ";    
    }

    return 0; 

}