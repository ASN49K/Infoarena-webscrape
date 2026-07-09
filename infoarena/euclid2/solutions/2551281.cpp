#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int div(int a, int b)
{
    if (a==b)
        return b;
    if (a>b)
        a = a-b;
    else
        b = b-a;
    return div(a, b);
}

int main()
{
    int t, a, b; in >> t;
    while (t>0)
    {
        in >> a >> b;
        out << div(a, b) << "\n";
        t--;
    }
}
