#include <iostream>
#include <fstream>

#define NMax 1024
using namespace std;

int A[NMax], B[NMax];
short N, M;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int matrix[NMax][NMax], subsir[NMax], count;

int main()
{
    in >> M >> N;
    for (int i = 1; i <= M; i++)
        in >> A[i];
    for (int i = 1; i <= N; i++)
        in >> B[i];

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
        {
            if (A[i] == B[j]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            if (A[i] != B[j])
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    for (int i = M; i >= 1;)
        for (int j = N; j >= 1;)
        {
            if (A[i] == B[j]) {
                subsir[count] = A[i];
                count++;
                i--; j--;
            }
            if (A[i] != B[i])
            {
                if (matrix[i][j - 1] > matrix[i - 1][j])
                    j--;
                else
                    i--;
            }
        }
    out << matrix[M][N] << "\n";

    for (; count-1 >= 0; count--)
        out << subsir[i] << " ";

    return 0;
}
