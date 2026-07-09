#include <fstream>

using namespace std;

#define MAX 1025
ofstream g("cmlsc.out");
int v1[MAX], v2[MAX], matrix[MAX][MAX];

void write_lcs(int matrix[MAX][MAX],int m, int n)
{
    if(m <= 0 || n <= 0) return;
    else
    {
        if(v1[m-1] == v2[n-1])
        {
            write_lcs(matrix, m-1, n-1);
            g<<v1[m-1]<<' ';
        }
        else
            if(matrix[m-1][n] >= matrix[m][n-1])
                write_lcs(matrix, m-1, n);
            else
                write_lcs(matrix, m, n-1);
    }
}
int main()
{
    ifstream f("cmlsc.in");
    int m,n,i,j;
    f >> m >> n;
    for(i = 0; i < m ; ++i) f >> v1[i];
    for(j = 0; j < n; ++j) f >> v2[j];
    for(i = 1; i <= m; ++i)
        for(j = 1; j <= n; ++j)
            if(v1[i-1] == v2[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
    g<<matrix[m][n]<<'\n';
    write_lcs(matrix, m, n);
    f.close();
    g.close();
    return 0;
}
