#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1024], b[1024], c[1025][1025];
vector<int> res;

int main()
{
    int m, n;
    f >> m >> n;
    for(int i = 0; i < m; i++)
        f >> a[i];
    for(int i = 0; i < n; i++)
        f >> b[i];

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            if(a[i - 1] == b[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if(c[i][j - 1] > c[i - 1][j])
                c[i][j] = c[i][j - 1];
            else
                c[i][j] = c[i - 1][j];
        }
    
    int i = m, j = n;
    while(i && j)
    {
        if(a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if(c[i][j - 1] <= c[i - 1][j])
            i--;
        else
            j--;
    }
    g << c[m][n] << "\n";
    for(int i = (int)res.size() - 1; i >= 0; i--)
        g << res[i] << " ";
    return 0;
}