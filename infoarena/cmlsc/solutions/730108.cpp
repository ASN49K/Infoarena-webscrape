#include <fstream>

using namespace std;

const int MAX = 1200;
int dp[MAX][MAX], L1, L2, a[MAX], b[MAX];

ofstream out("cmlsc.out");

void citire()
{
    ifstream in("cmlsc.in");
    in>>L1>>L2;
    in.get();
    for(int i = 1; i <= L1; i++)
        in>>a[i];
    for(int i = 1; i <= L2; i++)
        in>>b[i];
    in.close();
}

void detSubSir()
{
    for(int i = 1; i <= L1; i++)
        for(int j = 1; j <= L2; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    out<<dp[L1][L2]<<'\n';
}

void reconstituire(int i, int j)
{
    if(i && j)
    {
        if(a[i] == b[j])
        {
            reconstituire(i - 1, j - 1);
            out<<a[i]<<" ";
        }
        else
        {
            if(dp[i - 1][j] >= dp[i][j - 1])
                reconstituire(i - 1, j);
            else
                reconstituire(i, j - 1);
        }
    }
}

void solve()
{
    detSubSir();
    reconstituire(L1, L2);
}

int main()
{
    citire();
    solve();
    out.close();
    return 0;
}
