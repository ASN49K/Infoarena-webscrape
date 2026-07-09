#include    <fstream>

#define t_max(a, b) ((a > b) ? a : b)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1030], B[1030], DP[1030][1030], V[1030];
int M, N, answers;

void solve()
{
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
            {
                V[++answers] = A[i];
                DP[i][j] = 1 + DP[i-1][j-1];
            }
            else
                DP[i][j] = t_max(DP[i-1][j], DP[i][j-1]);
        }
    }
    
    fout << answers << "\n";
    for(int i = 1; i <= answers; i++)
        fout << V[i] << " ";
}

void read()
{
    fin >> M >> N;
    for(int i = 1; i <= M; i++)
        fin >> A[i];
    for(int i = 1; i <= N; i++)
        fin >> B[i];
    
    solve();
}

int main()
{
    read();
    return 0;
}
