#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define input "cmlsc.in"
#define output "cmlsc.out"
#define NMAX 260
using namespace std;

ifstream fin(input);
ofstream fout(output);

int dp[NMAX][NMAX];
int v1[NMAX], v2[NMAX];
vector <int> result;

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
    while(i >= 1 && j >= 1)
    {
        if(v1[i] == v2[j])
        {
            result.push_back(v1[i]);
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
    int lg = result.size();
    for(i = lg - 1; i >= 0; i--)
        fout << result[i] << " ";
    return 0;
}
