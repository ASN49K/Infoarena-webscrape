#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

int a[1025], b[1025], mat[1025][1025];
std::vector<int> v;

int main()
{
    int m, n;
    f >> m >> n;
    for (int i = 1; i <= m; i++)
        f >> a[i];
    for (int i = 1; i <= n; i++)
        f >> b[i];
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = std::max(mat[i - 1][j], mat[i][j - 1]);
    
    g << mat[m][n] << '\n';

    int i = m, j = n;
    while (i > 0) {
        if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i--;
            j--;
        }
        else if (mat[i - 1][j] > mat[i][j - 1])
            i--;
        else
            j--;
    }
    for (int z = v.size() - 1; z >= 0; z--)
        g << v[z] << " ";
    return 0;
}