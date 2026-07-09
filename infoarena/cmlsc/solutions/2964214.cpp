#include <fstream>
#include <vector>
using namespace std;

const int MAX = 1025;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[MAX][MAX] , a[MAX], b[MAX];

void afis_rec(int l, int c){
    if (l==0 || c==0)
    {
        return;
    }
    if (b[l]==a[c])
    {
        afis_rec(l-1,c-1);
        cout << b[l] << ' ';
    }
    else if (dp[l-1][c] > dp[l][c-1])
    {
        afis_rec(l-1,c);
    }
    else
    {
        afis_rec(l,c-1);
    }
}
int main()
{

    int n , m;
    cin >> n >> m;

    for(int i = 1 ; i <= n ;i++) cin >> a[i];
    for(int i = 1 ; i <= m ;i++) cin >> b[i];

    for(int i = 1 ; i <= m ;i++){
        for(int j = 1 ; j <= n ;j++){
            if(a[j]==b[i]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[m][n] << '\n';
    afis_rec(m,n);
    return 0;
}
