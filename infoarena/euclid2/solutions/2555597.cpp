#include <fstream>

using namespace std;

int main()
{
    int T, a, b, r;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> T;

    while(T)
    {
        f >> a >> b;

        while(b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        g << a << '\n';

        T --;
    }
    return 0;
}
