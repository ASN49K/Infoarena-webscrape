#include <fstream>

using namespace std;

int a[50][50];
int n, i, j, t, r;

int main()
{
    ifstream f("1.in");
    ofstream g("1.out");
    f >> t;
    for (i=1; i<=t; i++)
        for (j=1; j<=2; j++)
        f >> a[i][j];
    for (i=1; i<=t; i++)
        for (j=1; j<=2; j++)
        while(a[i][2])
        {
            r = a[i][1]%a[i][2];
            a[i][1] = a[i][2];
            a[i][2] = r;
        }
    g << a[i][1] << "\n";
    return 0;
}
