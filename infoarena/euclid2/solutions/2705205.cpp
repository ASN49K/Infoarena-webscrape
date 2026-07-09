#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int T, a[100001], b[100001], r, i;

int main()
{
    f >> T;
    for (i=1; i<=T; i++)
        f >> a[i] >> b[i];

    for (i=1; i<=T; i++)
    {
        f >> a[i] >> b[i];
        while(b[i]>0)
        {
            r = a[i] % b[i];
            a[i] = b[i];
            b[i] = r;
        }
        g << a[i] << "\n";
    }

    return 0;
}
