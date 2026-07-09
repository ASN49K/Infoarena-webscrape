#include<fstream>
using namespace std;

ifstream fin("tren.in");
ofstream fout("tren.out");

const int NMAX = 5e4 + 1;

int dp[NMAX][4],sum[NMAX]; // dp[i][j] = nr maxim de pasageri pentru primele i vagoane si j minilocomotive folosite


int main()
{
    int n,m;
    fin >> n;
    for(int i = 1; i <= n ; i++)
        {
            fin >> sum[i];
            sum[i] += sum[i - 1];
        }

    fin >> m;

    for(int i = 1; i <= n ; i++)
        {
            for(int l = 1; l <= 3; l++)
                {
                    if(i >= m)
                        {
                            dp[i][l] = max(dp[i - 1][l],dp[i - m][l - 1] + sum[i] - sum[i - m]);
                        }
                }
        }

    fout << dp[n][3];
}
