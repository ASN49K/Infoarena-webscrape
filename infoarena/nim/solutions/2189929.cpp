#include <fstream>

using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");
int n,m,i,j,x,suma;
int main()
{
    f >> n;
    for ( i = 1; i <= n; i++)
    {
        f >> m >> x;
        suma = x;
        for (j = 2; j <= m; j++)
        {
            f >> x;
            suma = suma ^ x;
        }
        if (suma == 0) g << "NU" << '\n';
        else g << "DA" << '\n';
    }
    return 0;
}
