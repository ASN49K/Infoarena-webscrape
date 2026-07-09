#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;

int main()
{
    f >> n >> m;
    vector<int>a(n+1), b(m+1);
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];
    vector<vector<int>>mat(n + 2, vector<int>(m + 2));
    for (int i = 0; i <= n; i++)
        mat[i][0] = 0;
    for (int i = 0; i <= m; i++)
        mat[0][i] = 0;
    for(int i=1;i<=n;i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
        }
    g << mat[n][m] << "\n";
    /*for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }*/
    int i = n, j = m;
    vector<int>sol;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if (mat[i][j - 1] < mat[i - 1][j])
                i--;
            else
                j--;
        }
    }
    for (int i = sol.size() - 1; i >= 0; i--)
        g << sol[i] << " ";
}
