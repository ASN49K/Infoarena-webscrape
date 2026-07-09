#include <algorithm>
#include <fstream>

std::pair<int *, int> longest_common_substring(int *A, int sizeA, 
                                               int *B, int sizeB)
{
    int **dp = new int*[sizeA + 1];
    for (int i = 0; i <= sizeA; ++i)
        dp[i] = new int[sizeB + 1];

    for (int i = 1; i <= sizeA; ++i)
        for (int j = 1; j <= sizeB; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    int k = dp[sizeA][sizeB];
    int size = dp[sizeA][sizeB];
    int *result = new int[size];

    int i = sizeA, j = sizeB;
    while (i != 0 && j != 0) {
        if (A[i - 1] == B[j - 1]) {
            result[--k] = A[i - 1];
            --i, --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    delete[] dp;

    return std::make_pair(result, size);
}

int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    int N, M;
    fin >> N >> M;

    int *A = new int[N];
    for (int i = 0; i < N; ++i)
        fin >> A[i];

    int *B = new int[M];
    for (int i = 0; i < M; ++i)
        fin >> B[i];

    std::pair<int *, int> aux_result = longest_common_substring(A, N, B, M);
    int size = aux_result.second;
    int *result = aux_result.first;

    fout << size << "\n";
    for (int i = 0; i < size; ++i) 
        fout << result[i] << " ";
    fout << "\n";

    delete[] A;
    delete[] B;
    delete[] result;

    return 0;
}
