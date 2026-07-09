#include <fstream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t, n, s = 0, p;
    in >> t;
    for (int i = 1; i <= t; i++)
    {
        in >> n;
        for (int j = 1; j <= n; j++)
        {
            in >> p;
            s ^= p;
        }
        if (s == 0)
            out << "NU";
        else
            out << "DA";
        out << '\n';
    }
    return 0;
}
