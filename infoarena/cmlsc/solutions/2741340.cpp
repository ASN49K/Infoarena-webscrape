#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, i, j, cnt;
int a[1030], b[1030], c[1030][1030], sol[1030];

int main()
{
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i =  1; i <= m; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j] , c[i][j-1]);
        }
    }
    fout << c[n][m] << '\n';
    i = n, j = m;
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            sol[++cnt] = a[i];
            i--, j--;
        }
        else
            if(c[i][j-1] < c[i-1][j])
                i--;
            else
                j--;
    }
    for (i = cnt; i >= 1; i--)
        fout << sol[i] <<  ' ';
    return 0;
}
