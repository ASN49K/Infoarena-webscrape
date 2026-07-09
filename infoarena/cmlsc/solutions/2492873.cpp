#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int LMAX = 1025;
int n, m,lg;
short A[LMAX], B[LMAX], C[LMAX][LMAX], S[LMAX];
int main()
{
    f >> m >> n;
    for(int i = 1; i <= m; i++)
        f >> A[i];
    for(int i = 1; i <= n; i++)
        f >> B[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(A[i] == B[j])
                C[i][j] = 1 + C[i - 1][j - 1];
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
    for(int i = m, j = n; i > 0;)
        if(A[i] == B[j])
            S[++lg] = B[i], i--, j--;
        else
            if(C[i - 1][j] < C[i][j - 1])
                j--;
            else
                i--;
    g << lg << '\n';
    for(int i = lg; i >= 1; i--)
        g << S[i] << ' ';
    return 0;

}
