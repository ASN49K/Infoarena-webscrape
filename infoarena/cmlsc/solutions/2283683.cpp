#include <fstream>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, i, j, k;
int v[1030], w[1030], sol[1030];
int d[1030][1030];

int main(){
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> v[i];
    for (i=1; i<=m; i++)
        fin >> w[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (v[i] == w[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max (d[i-1][j], d[i][j-1]);
    for (i=n; i>=1; i--)
        for (j=m; j>=1; j--){
            if (v[i] == w[j]){
                sol[++k] = v[i];
                i--, j--;
            }
            else{
                if (d[i-1][j] > d[i][j-1])
                    i--;
                else
                    j--;
            }
        }
    fout << d[n][m] << "\n";
    for (i=d[n][m]; i>=1; i--)
        fout << sol[i] << " ";
    return 0;
}
