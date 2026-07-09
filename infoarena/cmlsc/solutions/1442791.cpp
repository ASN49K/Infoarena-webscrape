#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s1[1025], s2[1025];
int LCS[1025][1025], m, n;
void open_file()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
}
void read()
{
    //gets(s1);
    //printf("%s\n", s1);
    //scanf("\n");
    //gets(s2);
    //printf("%s\n", s2);
    //scanf("\n");
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d", &s1[i]);
    }
    for(int j = 0; j < n; ++j)
    {
        scanf("%d", &s2[j]);
    }
}
void LCS_init()
{
    //printf("%d\n%d\n", m, n);
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(s1[i-1] == s2[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1]+1;
            }
            else
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
}
void recons_sol(int x, int y)
{
    if(LCS[x][y] != 0)
    {
        if(LCS[x][y] > LCS[x-1][y] && LCS[x][y] > LCS[x][y-1])
        {
            recons_sol(x-1, y-1);
            printf("%d ", s1[x-1]);
        }
        else
        {
            if(LCS[x-1][y] > LCS[x][y-1])
            {
                recons_sol(x-1, y);
                //printf("%c ", s1[x-1]);
            }
            else
            {
                recons_sol(x, y-1);
                //printf("%c ", s1[x-1]);
            }
        }
    }
}
int main()
{
    open_file();
    read();
    LCS_init();
    printf("%d\n", LCS[m][n]);
    recons_sol(m, n);
    return 0;
}
