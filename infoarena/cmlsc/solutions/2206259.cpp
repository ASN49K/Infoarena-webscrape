#include <algorithm>
#include <fstream>
#include <stack>

// A, B and M are 1-indexed.
const size_t MAX_MN = 1024 + 1;

int M, N, A[MAX_MN], B[MAX_MN], C[MAX_MN][MAX_MN];

int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    fin >> M >> N;
    for (int i = 1; i <= M; ++i)
        fin >> A[i];
    for (int j = 1; j <= N; ++j)
        fin >> B[j];

    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (A[i] == B[j])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = std::max(C[i - 1][j], C[i][j - 1]);

    int i = M, j = N;
    fout << C[i][j] << '\n';

    std::stack<int> s;

    while (C[i][j] != 0) {
        if (A[i] == B[j]) {
            s.push(A[i]);
            --i, --j;
        } else if (C[i][j - 1] < C[i - 1][j]) {
            --i;
        } else {
            --j;
        }
    }

    while (!s.empty()) {
        fout << s.top() << ' ';
        s.pop();
    }
    fout << '\n';

    return 0;
}
