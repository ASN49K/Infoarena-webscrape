#include <fstream>
#include <vector>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t, a, b, r;

int main()
{
    in >> t;

    while(t--)
    {
        in >> a >> b;
        r = a % b;
        while(r)
        {
            a = b;
            b = r;
            r = a % b;
        }
        out << b << '\n';
    }

    return 0;
}
