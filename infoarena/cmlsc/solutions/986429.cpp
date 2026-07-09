#include <fstream>
#include <cmath>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

int M, N, A[1025], B[1025], MAX, k, MAT[1025][1025], C[1025];

int main()
{
    is >> M;
    is >> N;
    for(int i = 1; i <= M; ++i)
        is >> A[i];
    for(int i = 1; i <= N; ++i)
        is >> B[i];
    for(int i = 1; i <= M; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            if(A[i] == B[j])
                MAT[i][j] =  MAT[i-1][j-1] +1;
            else
                MAT[i][j] = max( MAT[i-1][j],  MAT[i][j-1]);

        }
    }
    while(M != 0 && N != 0)
    {
        if(A[M] == B[N])
        {
            C[k] = A[M];
            k++;
            M--;
            N--;
        }
        else
            if(MAT[M-1][N] < MAT[M][N-1])
                N--;
            else
                M--;
    }
    os << k << '\n';
    for(int i = k - 1; i >= 0; i--)
    os << C[i] << ' ';
    is.close();
    os.close();
    return 0;
}
