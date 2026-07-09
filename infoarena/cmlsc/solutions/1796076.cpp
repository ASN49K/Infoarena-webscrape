#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n , m , a[1025] , b[1025] , p[1025][1025] , V[1025] , k;
void citire()
{
    f >> n >> m;
    for(int i = 1; i <= n ; ++i)
        f >> a[i];
    for(int i = 1; i <= n ; ++i)
        f >> b[i];
}
void PD1()
{
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
         if (a[i] == b[j])
            p[i][j] = 1 + p[i-1][j-1];
                else
            p[i][j] = max(p[i-1][j],p[i][j-1]);
}
void PD2()
{
    g << p[n][m] << '\n';
    int i = n , j = m;
    while(p[i][j] > 0)
    {
        if(a[i] == b[j])
        {
            V[k--] = a[i];
            i--; j--;
        }
        else
        {
            if (p[i][j - 1] > p[i - 1][j]) j--;
            else i--;
        }
    }
    for(int i = 1; i <= p[n][m]; ++i)
        g << V[i] << '\n';
}
int main()
{
    citire ();
    PD1();
    PD2();
    g.close ();
    return 0;
}
