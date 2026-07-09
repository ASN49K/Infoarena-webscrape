#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030], b[1030];
int d[1030][1030];
int sol[1030];
int main() {
    int m, n;
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int j = 1; j <= n; j++)
        fin >> b[j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    int lm = dp[m][n];
    fout<< lm << "\n";

    int i = m, j = n;
    int k = 0;

    while (i > 0 && j > 0){
        if (a[i] == b[j]){
            k++;
            sol[k] = a[i];
            i--;
            j--;
        }
        else if (d[i-1][j] >= d[i][j-1])
            i--;
        else
            j--;
    }
    for (int ord = k; ord >= 1; ord--)
        fout << sol[ord] << " ";
    return 0;
}
