#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int n, a, b, R;

int main()
{
    f >> n;

    while (n != 0)
    {
        f >> a >> b;

        while(b != 0)
        {
            R = a % b;
            a = b;
            b = R;
        }

        n--;

        g << a << endl;
    }

    return 0;
}
