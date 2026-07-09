#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1025], b[1025];
int dp[1025][1025];
int rez[1025];
int k;

int cel_mai_lung()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(max(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
        }

    return dp[n][m];
}

void subsir()
{
    int directie_i[] = {-1, 0};
    int directie_j[] = {0, -1};

    for(int i = n, j = m; i > 0, j > 0; )
    {
        if(a[i] == b[j])
        {
            rez[k++] = a[i];
            i--;
            j--;
        }
        else
        {
            int i_max = i - 1, j_max = j - 1;
            for(int d = 0; d < 2; ++d)
            {
                int iv = i + directie_i[d];
                int jv = j + directie_j[d];
                if(!(iv > 0 && jv > 0 && iv <= n && jv <= m))
                    continue;
                if(dp[iv][jv] > dp[i_max][j_max])
                {
                    i_max = iv;
                    j_max = jv;
                }
            }

            i = i_max;
            j = j_max;
        }
    }

    for(int i = k - 1; i >= 0; --i)
        fout << rez[i] << ' ';
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];
    fout << cel_mai_lung() << '\n';
    subsir();
    return 0;
}
