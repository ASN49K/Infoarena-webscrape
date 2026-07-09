#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n, a, b, r, v[100010];

int main ()
{
    in >> n;

    for (int i = 1; i <= n; i++)
    {
        in >> a >> b;

        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }

        out << a <<'\n';
    }


    return 0;
}
