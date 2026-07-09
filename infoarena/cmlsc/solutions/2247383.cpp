#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int LCS[1024];

int LCSLengthOf(int A[], int n, int B[], int m)
{
    if(n == 0 || m == 0)
        return 0;

    if(A[n-1] == B[m-1])
    {
        int len = LCSLengthOf(A, n-1, B, m-1) + 1;
        LCS[len-1] = A[n-1];
        return len;
    }

    return max(LCSLengthOf(A, n-1, B, m),LCSLengthOf(A, n, B, m-1));
}

int main()
{
    int M, N;
    fin >> M >> N;

    int A[1024], B[1024];
    for(int i=0; i<M; i++)
        fin >> A[i];
    for(int i=0; i<N; i++)
        fin >> B[i];

    int len = LCSLengthOf(A, M, B, N);
    fout << len << '\n';

    for(int i=0; i<len; i++)
        fout << LCS[i] << ' ';
    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}

