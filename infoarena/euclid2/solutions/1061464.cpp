#include <fstream>
using namespace std;

ifstream is ("euclid2.in");
ofstream os ("euclid2.out");

int a, b, c, T;

int main()
{
    is >> T;
    for (int t = 0; t < T; t++)
    {
        is >> a >> b;
        while (b != 0)
        {
            c = a % b;
            a = b;
            b = c;
        }
        os << a << '\n';
    }

    is.close();
    os.close();
    return 0;
}
