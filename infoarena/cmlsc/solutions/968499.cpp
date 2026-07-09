#include <fstream>
#include <vector>
#define NMAX 1025
using namespace std;

int D[NMAX][NMAX];

void input(int &M, vector<int> &A, int &N, vector<int> &B)
{
    ifstream in("cmlsc.in");
    in>>M>>N;
    A.resize(M+1); B.resize(N+1);
    for (int i=1; i<=M; ++i)
        in>>A[i];
    for (int i=1; i<=N; ++i)
        in>>B[i];
    in.close();
}

inline int maxim(const int &a, const int &b)
{
    return (a>b ? a : b);
}

void process(const int &M, const vector<int> &A, const int &N, const vector<int> &B)
{
    for (int i=1; i<=M; ++i)
        for (int j=1; j<=N; ++j)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else D[i][j] = maxim(D[i-1][j], D[i][j-1]);
}

void output(const int &M, const vector<int> &A, const int &N, const vector<int> &B)
{
    int i = M, j = N;
    int sol[NMAX], k = 0;
    while (i>0 && j>0)
        if (A[i] == B[j])
            sol[k++] = A[i], --i, --j;
        else if (D[i-1][j] > D[i][j-1])
            --i;
        else --j;
    ofstream out("cmlsc.out");
    out<<k<<"\n";
    for (i=k-1; i>=0; --i)
        out<<sol[i]<<" ";
    out.close();
}

int main()
{
    int M, N;
    vector<int> A, B;
    input(M, A, N, B);
    process(M, A, N, B);
    output(M, A, N, B);
    return 0;
}
