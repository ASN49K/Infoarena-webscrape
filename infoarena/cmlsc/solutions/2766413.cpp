#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[1025], b[1025], dp[1025][1025], sol[1025], lg;

void Citire();
void ConstrMat();
void ConstrSol();
void Afisare();

int main()
{
    Citire();
    ConstrMat();
    ConstrSol();
    Afisare();

    return 0;
}

void Citire()
{
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int j = 1; j <= n; j++)
        fin >> b[j];
}

void ConstrMat()
{
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void ConstrSol()
{
    int i = m, j = n;
    while(i)
        if(a[i] == b[j])
            sol[++lg] = a[i], i--, j--;
        else if(dp[i - 1][j] < dp[i][j - 1])
                j--;
        else
            i--;
}

void Afisare()
{
    fout << dp[m][n] << "\n";
    for(int i = lg; i >= 1; i--)
        fout << sol[i] << " ";
}
