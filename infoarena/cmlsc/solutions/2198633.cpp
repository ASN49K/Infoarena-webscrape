#include <iostream>
#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
#define NUM 1026
int a[NUM];
int b[NUM];
int mat[NUM][NUM];
int sir[NUM];
int n, m, lng;
using namespace std;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int j = 1; j <= m; ++j)
        f >> b[j];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = maxim(mat[i - 1][j], mat[i][j - 1]);
        }
    }

    lng = mat[n][m];
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            sir[lng--] = a[i];
            i--;
            j--;
        }
        else
        {
            if(mat[i][j - 1] > mat[i - 1][j])
                j--;
            else
                i--;
        }
    }

    g << mat[n][m] << "\n";
    for(int i = 1; i <= mat[n][m]; ++i)
        g << sir[i] << " ";
    f.close();
    g.close();
}
