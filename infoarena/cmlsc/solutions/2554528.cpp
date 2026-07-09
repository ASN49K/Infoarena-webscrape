#include <fstream>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[1025], b[1025], dp[1025][1025], ans[1025];
int n, m, nr;

void read ()
{
int i;
 f >> n >> m;
  for (i=1; i<=n; i++)
      f >> a[i];
  for (i=1; i<=m; i++)
      f >> b[i];
}

void dinamica ()
{
 int i, j;
  for (i=1; i<=n; i++)
  {
      for (j=1; j<=m; j++)
      {
          if (a[i] == b[j])
            dp[i][j] = 1 + dp[i-1][j-1];
          else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
  }
}

void solve ()
{
 int x, y, i;
  x = n, y = m;
   while (x && y)
   {
       if (a[x] == b[y])
       {
           nr ++;
           ans[nr] = a[x];
           x --, y --;
       }
       else {
         if (dp[x-1][y] > dp[x][y-1])
             x --;
         else
            y --;
       }
   }
 g << nr << '\n';
  for (i=nr; i>=1; i--)
    g << ans[i] << " ";
}

int main()
{
 read();
 dinamica();
 solve();
    return 0;
}
