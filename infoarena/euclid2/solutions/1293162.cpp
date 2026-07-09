#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n, x, y;

int sc(int a, int b)
{
    if(!b) return a;
    else return sc(b, a%b);
}

int main()
{
    in >> n;

    for( ; n; n--)
    {
        in >> x >> y;
        out << sc(x, y) << '\n';
    }

}
