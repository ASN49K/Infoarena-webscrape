#include <fstream>
#include <algorithm>

#define NMAX 1027

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m;
int a[NMAX], b[NMAX], Dp[NMAX][NMAX], Ans[NMAX];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int j = 1; j <= m; ++j)
        cin >> b[j];
    ///Dp[i][j] = lungimea maxima din primele i din A si primele j din B
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                Dp[i][j] = 1 + Dp[i - 1][j - 1];
            else
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
    for(int i = n, j = m; i; )
        if(a[i] == b[j]){
            Ans[++Ans[0]] = a[i];
            --i;
            --j;
        }
        else
            if(Dp[i - 1][j] > Dp[i][j - 1])
                --i;
            else
                --j;
    cout << Ans[0] << "\n";
    reverse(Ans + 1, Ans + Ans[0] + 1);
    for(int i = 1; i <= Ans[0]; ++i)
        cout << Ans[i] << " ";
    return 0;
}
