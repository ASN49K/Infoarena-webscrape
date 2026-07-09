#include <cstdio>
#include <algorithm>
#include <vector>
FILE *fin = freopen("cmlsc.in","r",stdin); FILE *fout = freopen("cmlsc.out","w",stdout);

static const int NMAX = 1024 + 5;

/* ----------- DATA ------------- */
int n,m;
int dp[NMAX][NMAX], a[NMAX], b[NMAX];
/* ----------- DATA ------------- */

void Read_Input()
{
    scanf("%d%d",&n,&m);
    for(int i =1 ; i<= n; ++i)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1; i<= m; ++i)
    {
        scanf("%d",&b[i]);
    }
}
void CommonSubstring()
{
    for(int i = 1; i<= n; ++i)
    {
        for(int j =1 ; j<= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
        }
    }

    std::vector<int> substring;

    int x = n, y = m;
    while(x> 0 && y > 0)
    {
        if(a[x] == b[y]){
            substring.push_back(a[x]);
            x--; y--;
        }
        else if(dp[x-1][y] > dp[x][y-1])
            x--;
        else
            y--;
    }
    printf("%d\n",dp[n][m]);
    for(int i = (int) substring.size()-1; i>= 0; i--)
        printf("%d ", substring[i]);

}

int main()
{
    Read_Input();
    CommonSubstring();
    return 0;
}
