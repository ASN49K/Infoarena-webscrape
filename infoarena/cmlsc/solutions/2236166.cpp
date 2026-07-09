#include <cstdio>
#include <algorithm>
#include <vector>
FILE *fin = freopen("cmlsc.in","r",stdin); FILE *fout = freopen("cmlsc.out","w",stdout);

static const int NMAX = 1024 + 5;

/* --------- Data ---------- */
int n, m;
int dp[NMAX][NMAX], a[NMAX], b[NMAX];
/* --------- Data ---------- */

void Read_Input()
{
    scanf("%d%d",&n,&m);
    for(int i =1 ;i <= n; ++i)
        scanf("%d",&a[i]);
    for(int i =  1; i <= m; ++i)
        scanf("%d",&b[i]);

    return;
}
void Construct_Matrix()
{
    for(int i = 1; i<= n; ++i)
    {
        for(int j =1 ; j<= m; ++j)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return;
}
void Print_Solution()
{
    std::vector<int> substring;
    printf("%d\n",dp[n][m]);
    int x = n, y = m;
    while(x && y)
    {
        if(a[x] == b[y])
        {
            substring.push_back(a[x]);
            x--; y--;
        }
        else if(dp[x-1][y] > dp[x][y-1])
            x--;
        else
            y--;
    }
    for(int i = (int) substring.size() - 1; i>= 0; i--)
        printf("%d ",substring[i]);

    return;
}

int main()
{
    Read_Input();
    Construct_Matrix();
    Print_Solution();

    return 0;
}
