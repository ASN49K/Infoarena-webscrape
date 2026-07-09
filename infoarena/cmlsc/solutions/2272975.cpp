#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DM =  2000;

int X[DM],Y[DM];
int dp[DM][DM];
int nra;
int afis[DM];

int main()
{
    int nrelx,nrely;
    fin >> nrelx >> nrely;
    for(int i = 1; i <= nrelx; i++) fin >> X[i];
    for(int i = 1; i <= nrely; i++) fin >> Y[i];
    
    for(int i = 1; i <= nrelx; i++)
        for(int j = 1; j <= nrely; j++)
            if(X[i] == Y[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    
    for(int i = nrelx, j = nrely; i && j; )
        if(X[i] == Y[j]) afis[++nra] = X[i], i--, j--;
        else if(dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    
    fout << dp[nrelx][nrely] << '\n';
    for(int i = nra; i >= 1; i--) fout << afis[i] << " ";
    
    return 0;
}
