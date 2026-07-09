#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A[1025], B[1025], Dp[1025][1025], n, m, recons[1025];

int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> A[i];
    for(int j = 1; j <= m; ++j) f >> B[j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i] == B[j]) Dp[i][j] = 1 + Dp[i-1][j-1];
            else Dp[i][j] = max(Dp[i-1][j], Dp[i][j-1]);

    int i = n, j = m, t = 0;
    while(i)
    {
        if(A[i] == B[j]) recons[++t] = A[i], --i, --j;
        else if(Dp[i-1][j] < Dp[i][j-1]) --j;
        else --i;
    }
        g << t << "\n";
        for(int i = t; i >= 1; --i)
            g << recons[i] << " ";
}
