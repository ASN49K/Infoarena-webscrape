#include <fstream>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, i, j, k;
int a[1100], b[1100], sol[1100];
int d[1100][1100];

int main(){
    fin >> n >> m;
    for (i=1; i<=n; i++){
        fin >> a[i];
    }
    for (i=1; i<=m; i++){
        fin >> b[i];
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=m; j++){
            if (a[i] == b[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else{
                d[i][j] = max (d[i-1][j], d[i][j-1]);
            }
        }
    }
    i = n, j = m;
    while (i >= 1 && j >= 1){
        if (a[i] == b[j]){
            sol[++k] = a[i];
            i--, j--;
        }
        else{
            if (d[i-1][j] > d[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for (i=d[n][m]; i>=1; i--){
        fout << sol[i] << " ";
    }
    return 0;
}
//recapitulare
