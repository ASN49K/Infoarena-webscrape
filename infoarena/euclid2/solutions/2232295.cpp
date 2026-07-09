#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    unsigned long T, a, b, r;
    ifstream f("euclid2.in");
    f >> T;
    ofstream g("euclid2.out");
    while (T)
    {
        f >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        g << a << endl;
        T--;
    }
    f.close();
    g.close();
    return 0;
}
