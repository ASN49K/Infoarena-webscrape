/// LONGEST COMMON SUBSEQUENCE
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#define NMax 1027
///#define f cin
///#define g cout
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B;
int a[NMax], b[NMax], dp[NMax][NMax], sir[NMax], ans;

int main()
{
    f >> A >> B;
    for(int i = 1; i <= A; ++i)
        f >> a[i];
    for(int i = 1; i <= B; ++i)
        f >> b[i];

    for(int i = 1; i <= A; ++i)
        for(int j = 1; j <= B; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    g << dp[A][B] << '\n';

    int i_curent = A, j_curent = B;
    while(i_curent)
    {
        if(a[i_curent] == b[j_curent])
        {
            sir[++ans] = a[i_curent];
            --i_curent, --j_curent;
        }
        else if(dp[i_curent][j_curent] > dp[i_curent - 1][j_curent]) --j_curent;
        else --i_curent;
    }

    for(int i = ans; i >= 1; --i)
        g << sir[i] << " ";
    return 0;
}
