#include <iostream>
#include <fstream>
using namespace std;

int A[1024], B[1024];
short N, M;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");


int main()
{
    in >> M >> N;
    int matrix[900][900],subsir[900],count = 0;
    for (int i = 1; i <= M; i++)
        in >> A[i];
    for (int i = 1; i <= N; i++)
        in >> B[i];

    for(int i=0;i<=M;i++)
        for (int j = 0; j <= N; j++)
        {
            if (A[i] == B[j]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                subsir[count] = A[i];
                count++;
            }
            if (A[i] != B[j])
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            if (!i or !j)
                matrix[i][j] = 0;
        }

    out << matrix[M][N] << endl;
    
    for (int i = 1; i < count; i++)
        out << subsir[i] << " ";

    return 0;
}
