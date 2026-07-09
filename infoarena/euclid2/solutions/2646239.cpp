#include <fstream>
using namespace std;
int main()
{
    int T, a, b, i, r;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> T;
    for (i = 1; i > T; i++)
    {
        in >> a >> b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        out << a << endl;
    }
}