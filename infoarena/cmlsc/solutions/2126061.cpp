#include <fstream>
#include <vector>
using namespace std;

ifstream is("cmlsc.in");
ofstream os("cmlsc.out");

void get_input(int& M, int& N, vector<int>& A, vector<int>& B);
void compute_lcs_length(vector<vector<int> >& D, vector<int>& A, vector<int>& B);
void backtrack_choices(vector<int>& LCS, vector<vector<int> >& D, vector<int>& A, vector<int>& B, int i, int j);

int main()
{
    int M, N;
    vector<int> A, B;
    vector<vector<int> > D;
    vector<int> LCS;

    get_input(M, N, A, B);
    compute_lcs_length(D, A, B);
    backtrack_choices(LCS, D, A, B, M, N);

    os << D[A.size() - 1][B.size() - 1] << '\n';
    for (auto x = LCS.begin(); x != LCS.end(); ++x)
        os << *x << " ";
}

void get_input(int& M, int& N, vector<int>& A, vector<int>& B)
{
    is >> M >> N;

    A.resize(M+1);
    B.resize(N+1);
    for (int i = 1; i < A.size(); ++i)
        is >> A[i];
    for (int i = 1; i < B.size(); ++i)
        is >> B[i];
}

void compute_lcs_length(vector<vector<int> >& D, vector<int>& A, vector<int>& B)
{
    D.resize(A.size());
    for (int i = 0; i < D.size(); ++i)
        D[i].resize(B.size());

    for (int i = 1; i < A.size(); ++i)
        for (int j = 1; j < B.size(); ++j)
        {
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else
                D[i][j] = max(D[i-1][j], D[i][j-1]);
        }
}

void backtrack_choices(vector<int>& LCS, vector<vector<int> >& D, vector<int>& A, vector<int>& B, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    else if (A[i] == B[j]) {
        backtrack_choices(LCS, D, A, B, i-1, j-1);
        LCS.push_back(A[i]);
    }
    else if (D[i-1][j] > D[i][j-1])
        backtrack_choices(LCS, D, A, B, i-1, j);
    else
        backtrack_choices(LCS, D, A, B, i, j-1);
}






