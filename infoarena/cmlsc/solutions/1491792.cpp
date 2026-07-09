#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int MAX = 1025;
int dp[MAX][MAX], a[MAX], b[MAX], na, nb, sol[MAX];
#define maxi(a, b) ((a)>(b))?(a):(b)
int main()
{
    fin>>na>>nb;
    for(int i=1; i<=na; i++) fin>>a[i];
    for(int i=1; i<=nb; i++) fin>>b[i];
    for(int i=1; i<=na; i++)
        for(int j=1; j<=nb; j++)
            if(a[i]==b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = maxi(dp[i-1][j], dp[i][j-1]);
    int x = na, y = nb;
    while(dp[x][y])
    {
        if(a[x]==b[y]){
            sol[dp[x][y]] = a[x];
            x--; y--;
        }
        else
            if(dp[x-1][y]>dp[x][y-1])
                x--;
            else
                y--;
    }
    fout<<dp[na][nb]<<'\n';
    for(int i=1; i<=dp[na][nb]; i++)
        fout<<sol[i]<<' ';
    return 0;
}
