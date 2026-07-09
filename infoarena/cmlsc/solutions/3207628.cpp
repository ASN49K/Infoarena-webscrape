#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int NMAX = 1030;
int n, m, dp[NMAX + 5][NMAX + 5], v[NMAX + 5], x[NMAX + 5];
vector <int> rez;

void build_dp()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(v[i] == x[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}

void get_values()
{
    int i = n, j = m;

    while(i)
    {
        if(v[i] == x[j])
        {
            rez.push_back(v[i]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int j = 1; j <= m; j++)
        fin >> x[j];

    build_dp();

    get_values();

    fout << rez.size() << '\n';

    for(int i = rez.size() - 1; i >= 0; i--)
        fout << rez[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
