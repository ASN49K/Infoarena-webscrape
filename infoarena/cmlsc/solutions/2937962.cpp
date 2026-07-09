#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int a[1025], b[1025];
int dp[1025][1025];

void refacere_subsir(int l, int c){
    if(l == 0 || c == 0)
        return;
    if(a[l] == b[c]){
        refacere_subsir(l - 1, c - 1);
        fout << a[l] << " ";
    }else if(dp[l][c - 1] > dp[l - 1][c])
        refacere_subsir(l, c - 1);
    else
        refacere_subsir(l - 1, c);
}

int main()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] != b[j])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j]=  dp[i - 1][j - 1] + 1;
        }
    }

    fout << dp[m][n] << "\n";
    refacere_subsir(m, n);

    return 0;
}
