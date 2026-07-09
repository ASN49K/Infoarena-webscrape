#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout("cmlsc.out");

    int N, M;

    fin >> N >> M;

    vector<int> v1(N + 1);
    vector<int> v2(M + 1);

    for (int i = 0; i < N; ++i)
        fin >> v1[i + 1];

    for (int j = 0; j < M; ++j)
        fin >> v2[j + 1];

    vector<vector<int> > m(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (v1[i] == v2[j]) {
                m[i][j] = m[i - 1][j - 1] + 1;
            } else {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    fout << m[N][M] << '\n';

    vector<int> result;
    int i = N, j = M;

    while (i >= 1 && j >= 1) {
        if (v1[i] == v2[j]) {
            result.push_back(v1[i]);
            --i; --j;
        } else if (m[i - 1][j] < m[i][j - 1]) {
            --j;
        } else {
            --i;
        }
     }

    for (int i = result.size() - 1; i >= 0; --i) {
        fout << result[i] << ' ';
    }

    fin.close();
    fout.close();

    return 0;
}
