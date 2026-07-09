#include<fstream>

#define NMAX 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int ans[NMAX];
int n, m, cnt;

int main()
{
    fin >> n >> m;

    int v[n + 1];
    int v1[m + 1];

    for(int i = 1; i <= n; i++)
        fin >> v[i];
    for(int i = 1; i <= m; i++)
        fin >> v1[i];
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(v1[i] == v[j])
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else
            {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i != 0 && j != 0)
    {
        if(v[i] == v1[j])
        {
            ans[++cnt] = v[i];
            i--;
            j--;
        }
        else if(a[i - 1][j] < a[i][j - 1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    fout << cnt << '\n';
    for(int i = cnt; i >= 1; i--)
    {
        fout << ans[i] << " ";
    }
    return 0;
}
