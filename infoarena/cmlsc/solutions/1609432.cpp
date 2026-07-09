#include <fstream>

using namespace std;
#define MAX 1025
#define maxim(a, b) ((a > b) ? a : b)
ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");
int v1[MAX], v2[MAX], sol[MAX], table[MAX][MAX];
int main()
{
    int n, m;
    int i, j;
    fin >> n >> m;
    for( i = 1; i <= n; i++)
        fin >> v1[i];
    for( i = 1; i <= m; i++)
        fin >> v2[i];
    for(i = 1 ; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(v2[i] == v1[j])
                    table[i][j] =  1 + table[i-1][j-1];
                    else table[i][j] = maxim(table[i][j-1], table[i-1][j]);
    fout << table[m][n] << "\n";
    j=0;
    for(i = 1; i <= n; i++)
        if( j != table[m][i])
        {
            j++;
            fout << v1[i] << " ";
        }

    fin.close();
    fout.close();
    return 0;
}
