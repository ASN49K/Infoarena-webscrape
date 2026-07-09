#include <fstream>
#include <vector>


int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    int N, M;
    fin >> N >> M;

    std::vector<int> v1(N), v2(M);
    for (int i = 0; i < N; ++i)
        fin >> v1[i];

    for (int i = 0; i < M; ++i)
        fin >> v2[i];
    fin.close();

    std::vector< std::vector<int> > D(N+1, std::vector<int>(M+1));
    for (int i = 0; i <= N; ++i)
        D[i][0] = 0;
    for (int i = 0; i <= M; ++i)
        D[0][i] = 0;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            if (v1[i-1] == v2[j-1])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = std::max(D[i-1][j], D[i][j-1]);
        }

    std::vector<int> seq;
    for (int i = N, j = M; i; ) {
        if (v1[i-1] == v2[j-1]) {
            seq.push_back(v1[i-1]);
            --i;
            --j;
        } else if (D[i-1][j] < D[i][j-1]) {
            --j;
        } else {
            --i;
        }
    }

    fout << D[N][M] << "\n";
    for (auto it = seq.crbegin(); it != seq.crend(); ++it)
        fout << *it << " ";
    fout << "\n";

    fout.close();
    return 0;
}
