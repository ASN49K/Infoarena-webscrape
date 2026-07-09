#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1025;

int a[Nmax], b[Nmax], dp[Nmax][Nmax];

void reconst(int lin, int col){
    if(dp[lin][col] == 0){
        return;
    }

    int val, l;

    l = lin;
    val = dp[lin][col] - 1;
    lin--;
    col--;

    while(dp[lin][col] == val){
        lin--;
    }
    lin++;
    while(dp[lin][col] == val){
        col--;
    }
    col++;

    reconst(lin, col);

    fout << a[l] << " ";
}

int main()
{
    int n, m, lenmax, lmax, cmax;

    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        fin >> b[j];
    }

    lenmax = 0;
    lmax = -1;
    cmax = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if(dp[i][j] > lenmax){
                    lenmax = dp[i][j];
                    lmax = i;
                    cmax = j;
                }
            }
            else{
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    fout << lenmax << '\n';

    reconst(lmax, cmax);

    return 0;
}
