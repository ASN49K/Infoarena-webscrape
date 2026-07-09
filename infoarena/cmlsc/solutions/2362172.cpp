#include <iostream>
#include <fstream>
#include <stack>
#define NMAX 1024
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int M, N;
int dp[NMAX][NMAX];
int step[NMAX][NMAX];
int first[NMAX];
int second[NMAX];
stack<int> nodes;

int main()
{
    fi >> M >> N;
    for(int i = 1; i <= M; ++i)
        fi >> first[i];
    for(int j = 1; j <= N; ++j)
        fi >> second[j];

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            if(second[i] == first[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                step[i][j] = 3;
            }
            else if( dp[i-1][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                step[i][j] = 2;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                step[i][j] = 1;
            }
        }
    }
    fo << dp[N][M] << "\n";

    while(M != 0 && N != 0)
    {
        if(step[N][M] == 3)
        {
            nodes.push(second[N]);
            N--;
            M--;
        }
        else if(step[N][M] == 2)
            N--;
        else
            M--;
    }
    while(!nodes.empty())
    {
        fo << nodes.top()<<" ";
        nodes.pop();
    }
}
