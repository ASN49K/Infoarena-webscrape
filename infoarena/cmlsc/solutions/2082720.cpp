/// LONGEST COMMON SUBSEQUENCE
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <assert.h>
#define NMax 1027
///#define f cin
///#define g cout
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B;
int a[NMax], b[NMax], ans, sir[NMax], dp[NMax][NMax];

int main()
{
    f >> A >> B;
    for(int i = 0; i < A; ++i)
        f >> a[i];

    for(int i = 0; i < B; ++i)
        f >> b[i];

    for(int i = 0; i < A; ++i)
        for(int j = 0; j < A; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    g << dp[A - 1][B - 1] << '\n';

    int i_curent = A - 1, j_curent = B - 1;
    while(i_curent > -1)
    {
        if(a[i_curent] == b[j_curent])
        {
            sir[++ans] = a[i_curent];
            --i_curent, --j_curent;
        }
        else if(dp[i_curent][j_curent] > dp[i_curent - 1][j_curent]) --j_curent;
        else --i_curent;
    }

    for(int i = ans; i > 0; --i)
        g << sir[i] << " ";
    return 0;
}
