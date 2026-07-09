#include <fstream>

#define NMAX 1030

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int DP[NMAX][NMAX], N, M, sir1[NMAX], sir2[NMAX], conx[NMAX], K;

void Read_Data()
{
    in >> N >> M;
    for(int i = 1; i <= N; i++)
        in >> sir1[i];
    for(int i = 1; i <= M; i++)
        in >> sir2[i];
}

void Solve_DP()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(sir1[i] == sir2[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
}

void Recreate_Arr()
{
    int i = N, j = M;
    while(i >= 1 && j >= 1)
    {
        if(sir1[i] == sir2[j]) conx[++K] = sir1[i], i--, j--;
        else if(DP[i][j] == DP[i-1][j]) i--;
        else if(DP[i][j] == DP[i][j-1 ]) j--;
    }
    out << K << "\n";
    for(int i = K; i >= 1; i--)
        out << conx[i] << " ";
}

int main()
{
    Read_Data();
    Solve_DP();
    Recreate_Arr();
    return 0;
}
