#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t, a, b; in >> t;
    while (t>0)
    {
        in >> a >> b;
        while (a!=b)
        {
            if (a>b)
                a = a-b;
            else
                b = b-a;
        }
        out << a << "\n";
        t--;
    }
}
