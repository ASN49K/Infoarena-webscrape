#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMax = 1e3 + 25;

int n, m;
int a[NMax + 5], b[NMax + 5], dp[NMax + 5][NMax + 5], v[NMax + 5];

void Read(){
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
}

void DP(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}

void Construct(){
    int i = n, j = m, length = 0;
    while (i && j){
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else{
            v[++length] = a[i];
            i--, j--;
        }
    }
}

void Print(){
    fout << dp[n][m] << '\n';
    for (int i = dp[n][m]; i >= 1; i--)
        fout << v[i] << ' ';
    fout << '\n';
}

int main(){
    Read();
    DP();
    Construct();
    Print();
    return 0;
}
