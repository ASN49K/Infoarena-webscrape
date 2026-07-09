#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    long long a,b,c;
    int t,i;
    f >> t;
    for (i = 0; i < t; i++)
    {
        f >> a >> b;

        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g << a << "\n";
    }
    f.close();
    g.close();
}
