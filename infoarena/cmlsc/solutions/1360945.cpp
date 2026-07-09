#include <stdio.h>
#include <vector>

#define UP 1
#define LEFT 2
#define BINGO 3

int dp[1025][1025], path[1025][1025];
std::vector<int> sol;

int max(int a, int b)
{
    if(a>b)return a;
    return b;
}

int main()
{
    FILE* IN   = fopen("cmlsc.in", "r");
    FILE* OUT  = fopen("cmlsc.out", "w");

    int n, m, i, j, maximum=0, a[1025], b[1025], max_i, max_j;

    fscanf(IN, "%d%d", &n, &m);
    for(i=1;i<=n;i++)
        fscanf(IN, "%d", &a[i]);
    for(i=1;i<=m;i++)
        fscanf(IN, "%d", &b[i]);

    for( i=1; i<=n; i++)
    {
        for( j=1; j<=m; j++)
        {
            if( a[i] == b[j] )
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                path[i][j] = BINGO;
            }
            else
            {
                if( dp[i-1][j] > dp[i][j-1] )
                {
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = UP;
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                    path[i][j] = LEFT;
                }
            }
            if(dp[i][j]>maximum)
            {
                maximum = dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    i = max_i;
    j = max_j;
    while( dp[i][j] != 0 )
    {
        if( path[i][j] == UP )
            i--;
        else if( path[i][j] == LEFT )
            j--;
        else
        {
            sol.push_back( b[j] );
            i--;
            j--;
        }
    }

    fprintf(OUT, "%d\n", maximum);
    for( i = sol.size() - 1 ; i>=0; i--)
        fprintf(OUT, "%d ", sol[i]);

    return 0;
}
