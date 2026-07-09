#include <fstream>
#include <vector>
using namespace std;

vector<int> sol;
int max_length = 0;

inline int MAX(const int &a, const int &b)
{
    return (a>b ? a : b);
}

int LCS(const vector<int> &A, const int &A_size, const vector<int> &B, const int &B_size)
{
    if (A_size<0 || B_size<0)
        return 0;

    if (A[A_size] == B[B_size])
    {
        int current_length = 1 + LCS(A, A_size-1, B, B_size-1);
        if (current_length > max_length)
        {
            sol.push_back(A[A_size]);
            max_length = current_length;
            return max_length;
        }
    }

    return MAX(LCS(A, A_size-1, B, B_size), LCS(A, A_size, B, B_size-1));
}

int main()
{
    vector<int> A, B;
    int i, N, M, k;

    ifstream in("cmlsc.in");
    in>>M>>N;
    for (i=0; i<M; ++i)
    {
        in>>k;
        A.push_back(k);
    }
    for (i=0; i<N; ++i)
    {
        in>>k;
        B.push_back(k);
    }
    in.close();

    ofstream out("cmlsc.out");
    out<<LCS(A, M-1, B, N-1)<<"\n";
    for (int i=0; i<sol.size(); ++i)
        out<<sol[i]<<" ";
    out.close();

    return 0;
}
