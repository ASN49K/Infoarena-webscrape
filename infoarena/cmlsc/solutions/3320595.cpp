#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define N 1025
int n, m, a[N], b[N], dp[N][N], sol[N], k;
void citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= m; i++)
        fin >> b[i];
}
void pd()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int i = n, j = m;
    while(i && j)
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    fout << k << "\n";
    for(i = k; i >= 1; i--)
        fout << sol[i] << " ";

}
int main()
{
    citire();
    pd();
    return 0;
}
