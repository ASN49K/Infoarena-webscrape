#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int t, n, x, s;
    ifstream f ("nim.in");
    ofstream g ("nim.out");

    f >> t;
    while(t--)
    {
        f >> n;
        s = 0;
        while(n--)
        {
            f >> x;
            s = s ^ x;
        }
        if (s > 0)
            g << "DA\n";
        else
            g << "NU\n";
    }

    return 0;
}
