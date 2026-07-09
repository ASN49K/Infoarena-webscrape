#include <bits/stdc++.h>
using namespace std;
using pii = pair<short int,short int>;
//#define fin cin
//#define fout cout
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax = (1<<10) + 1;
int n , m , a[nmax] , b[nmax] , dp[nmax][nmax];
pii pre[nmax][nmax];
struct rem
{
    short int val , i , j;
};
rem best[nmax][nmax];
void rec(int x , int y)
{
    if(x == 0) return;
    rec(pre[x][y].first,pre[x][y].second);
    fout << a[x] << ' ';
}
signed main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= n ; ++i) fin >> a[i];
    for(int i = 1 ; i <= m ; ++i) fin >> b[i];
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
            if(a[i] != b[j])
            {
                dp[i][j] = 0;
            }
            else
            {
                int mx = 0;
                if(i-1 >= 1 && j-1 >= 1) mx = best[i-1][j-1].val;
                if(mx > 0)
                {
                    dp[i][j] = mx + 1;
                    pre[i][j] = {best[i-1][j-1].i,best[i-1][j-1].j};
                }
                else
                {
                    dp[i][j] = 1;
                    pre[i][j] = {0,0};
                }
            }
            int mx = dp[i][j];
            pii to = {i,j};
            if(i-1 >= 1 && best[i-1][j].val > mx)
            {
                mx = best[i-1][j].val;
                to = {best[i-1][j].i,best[i-1][j].j};
            }
            if(j-1 >= 1 && best[i][j-1].val > mx)
            {
                mx = best[i][j-1].val;
                to = {best[i][j-1].i,best[i][j-1].j};
            }
            best[i][j] = {mx,to.first,to.second};
        }
    }
    fout << best[n][m].val << '\n';
    rec(best[n][m].i,best[n][m].j);
    return 0;
}
