#include<fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n , m , a[1025] , b[1025] , x[1025][1025] , sol[1025] , k;
void citire ()
{
    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    for (int i = 1; i <= m; ++i)
        f >> b[i];
}
void rezolvare ()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                x[i][j] = 1 + x[i-1][j-1];
            else
                x[i][j] = max(x[i-1][j] , x[i][j-1]);
}
void rezolvare2()
{   g << x[n][m] << '\n';
    int i = n , j = m;
    while (x[i][j])
    {
    	if (a[i] == b[j])
    	{
     	   sol[++k] = a[i];
     	   i--; j--;
    	}
    	else
    	{
    	    if (x[i-1][j] > x[i][j-1]) i--;
     	   else j--;
        }
    	for (; k > 0; --k) g << sol[k] << ' ';
    }
}
int main ()
{
    citire();
    rezolvare();
    rezolvare2();
    g.close ();
    return 0;
}
