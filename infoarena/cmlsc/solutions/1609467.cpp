#include <fstream>

using namespace std;
#define MAX 1025
#define maxim(a, b) ((a > b) ? a : b)
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int v1[MAX], v2[MAX], sol[MAX], table[MAX][MAX];
int main()
{
    int n, m, nr = 0;
    int i, j;
    fin >> n >> m;
    for( i = 1; i <= n; i++)
        fin >> v1[i];
    for( i = 1; i <= m; i++)
        fin >> v2[i];
    for(i = 1 ; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(v1[i] == v2[j])
                    table[i][j] =  1 + table[i-1][j-1];
                    else table[i][j] = maxim(table[i][j-1], table[i-1][j]);
    fout << table[n][m] << "\n";
    i=n;
    j=m;
    while(i)
        if(v1[i] == v2[j])
        {
            sol[++nr] = v1[i];
            --i;
            --j;
        }
        else if(table[i-1][j] < table[i][j-1])
            --j;
        else --i;
    for( i = nr; i ; i--)
        fout << sol[i] << " ";
    fin.close();
    fout.close();
    return 0;
}
