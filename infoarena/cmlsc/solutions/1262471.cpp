#include <fstream>
#define Nmax 1025
using namespace std;
int a[Nmax], b[Nmax], sol[Nmax][Nmax], sir[Nmax];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
    int n, j, m, i;
    f >> n >> m;
    for(i = 1; i<=n; i++) f >> a[i];
    for(i = 1; i<=m; ++i) f >> b[i];
    //presupunem ca a[i][j] reprezinta cel mai lung subsir comun pana la a[i], b[j];
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=m; j++)
            if(a[i] == b[j])
            sol[i][j] = 1 + sol[i - 1][j];
        else sol[i][j] = max(sol[i - 1][j], sol[i][ j -1]);
    }
    g << sol[n][m]<<'\n';
   int nr = sol[n][m];
   i = n; j = m;
   while(nr)
   {
        if(sol[i - 1][j] == nr)
            i --;
        else if(sol[i][j - 1] == nr)
            j --;
        else {
            sir[nr] = a[i];
            i --;
            j --; nr--;
        }
   }
   for(i = 1; i<=sol[n][m];i++)
    g << sir[i] << ' ';
   return 0;
}
