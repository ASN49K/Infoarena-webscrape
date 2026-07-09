#include <fstream>

using namespace std;

int a[50][50];
int i, j, T, r;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> T;
    for (i=1; i<=T; i++)
        for (j=1; j<=2; j++)
        f >> a[i][j];
    for (i=1; i<=T; i++)
        for (j=1; j<=2; j++)
        while(a[i][2]!=0)
        {
            r = a[i][1]%a[i][2];
            a[i][1] = a[i][2];
            a[i][2] = r;
        }
    for (i=1; i<=T; i++)
        g << a[i][1] << "\n";
    return 0;
}
