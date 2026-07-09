/*
    Keep It Simple!
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define MaxN 1025

int A[MaxN],B[MaxN],Dp[MaxN][MaxN],N,M;
vector<int> Final;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> N >> M;

    for(int i=1;i<=N;i++) f >> A[i];
    for(int j=1;j<=M;j++) f >> B[j];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            if(A[i] == B[j])
                Dp[i][j] = Dp[i-1][j-1] + 1;
            else
                Dp[i][j] = max(Dp[i-1][j],Dp[i][j-1]);
        }
    g << Dp[N][M] << "\n";

    int x = N,y = M;
    while(x>=1 && y>=1)
    {
        if(A[x] == B[y])
        {
            Final.push_back(A[x]);
            x--,y--;
        }
        else  if(Dp[x-1][y] > Dp[x][y-1])
            x--;
        else
            y--;
    }

    for(size_t i=Final.size()-1; i > 0; i--)
        g << Final[i] << " ";
        g << Final[0];
}
