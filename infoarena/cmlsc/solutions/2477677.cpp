#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define input "cmlsc.in"
#define output "cmlsc.out"
#define NMAX 1024
using namespace std;

ifstream fin(input);
ofstream fout(output);

int dp[NMAX][NMAX];
int v1[NMAX], v2[NMAX];
int result[NMAX];

int main()
{
    int N, M;
    fin >> N >> M;
    for(int i = 1; i <= N ; i++)
        fin >> v1[i];
    for(int i = 1; i <= M ; i++)
        fin >> v2[i];
    for(int i = 1; i <= N ; i++)
    {
        for(int j = 1; j <= M ; j++)
        {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j  - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[N][M] << "\n";
    int i = N , j = M;
    int cnt = 0;
    while(i >= 1 && j >= 1)
    {
        if(v1[i] == v2[j])
        {
            result[++cnt] = v1[i];
            i--;
            j--;
            continue;
        }
        if(dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
            continue;
        }
        i--;
    }
    for(i = cnt; i >= 1; i--)
        fout << result[i] << " ";
    return 0;
}
