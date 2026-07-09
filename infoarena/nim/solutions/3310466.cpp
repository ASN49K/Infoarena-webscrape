#include <fstream>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int t, n, x, y;
int main()
{
    in >> t;
    while(t)
    {
        --t;
        in >> n;
        in >> x;
        while(--n)
        {
            in >> y;
            x ^= y;
        }
        if (x == 0)
            out << "NU\n";
        else
            out << "DA\n";
    }
    return 0;
}
