#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long long a,b;
    int t,i;
    fstream f("euclid2.in", ios::in);
    f >> t;
    fstream g("euclid2.out", ios::out);
    for (i = 0; i < t; i++)
    {
        f >> a >> b;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g << a << endl;
    }
    f.close();
    g.close();
}
