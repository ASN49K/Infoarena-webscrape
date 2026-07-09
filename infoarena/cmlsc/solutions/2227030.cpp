#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int N, M, A[1025], B[1025], C[1025][1025];

int main()
{
    in >> N >> M;

    int i, j;
    for(i = 1; i <= N; ++i)
        in >> A[i];
    for(j = 1; j <= M; ++j)
        in >> B[j];

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
        {
            if(A[i] == B[j])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }

    out << C[N][M] << endl;

    int subsir[1025], k=0;

    i = N;
    j = M;

    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            ++k;
            subsir[k] = A[i];
            i--; j--;
        }
        else if(C[i - 1][j] > C[i][j - 1])
                i--;
            else
                j--;
    }

    for(i = k; i >= 1; --i)
        out << subsir[i] << " ";

    return 0;
}
