#include <iostream>
#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, s, n, aux;
int main()
{
    f >> t;
    for(int i = 1; i <= t; i++)
    {
        s = 0;
        f >> n;
        for(int j = 1; j <= n; j++)
        {
            f >> aux;
            s ^= aux;
        }

        if(s == 0) g << "NU" << '\n';
        else g << "DA" << '\n';
    }


    return 0;
}
