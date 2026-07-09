#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define limn 1030
int A[limn], B[limn];
int N, M;
int dp[limn][limn];
int rez[limn];

void afisare()
{
    int dr = 0;
    int i, j;
    i = N;
    j = M;
    while(i>=1 && j>=1)
    {
        if(A[i] == B[j])
        {
            dr++;
            rez[dr] = A[i];
        }
        if(dp[i][j-1] < dp[i-1][j])
            i--;
        else j--;
    }

    for(i=dr; i>=1; i--)
        fout<<rez[i]<<' ';
}

int main()
{
    fin>>N>>M;
    for(int i=1; i<=N; i++)
        fin>>A[i];
    for(int j=1; j<=M; j++)
        fin>>B[j];

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    fout<<dp[N][M]<<'\n';
    afisare();


    fin.close();
    return 0;
}
