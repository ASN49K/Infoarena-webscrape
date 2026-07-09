#include <iostream>
#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int x, n, S;

int main()
{
    int T;
    f >> T;
    while(T--)
    {
        f >> n;
        while(n--)
        {
            f >> x;
            S ^= x;
        }
        if(S != 0)
            g << "DA\n";
        else g << "NU\n";
    }

    return 0;
}
