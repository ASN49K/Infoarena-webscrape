#include    <iostream>
#include    <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NLIM = 1030;

int N, M;
int A[NLIM], B[NLIM];
int DP[NLIM][NLIM];
int V[NLIM], answers;

void Read()
{
    fin >> M >> N;
    for(int i = 1; i <= M; i++)
        fin >> A[i];
    for(int j = 1; j <= N; j++)
        fin >> B[j];

    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }

    for(int i = M, j = N; ;)
    {
        if(A[i] == B[j])
        {
            V[++answers] = A[i];
            i -= 1; j -= 1;
        }
        else
            if(DP[i-1][j] < DP[i][j-1])
                j -= 1;
            else
                i -= 1;

        if(i == 0 || j == 0)
            break;
    }

    fout << answers << "\n";
    for(int i = answers; i > 0; i--)
        fout << V[i] << " ";
}

int main()
{
    Read();
    return 0;
}
