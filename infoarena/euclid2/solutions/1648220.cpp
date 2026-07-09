#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int T, a, b;

int mcd(int a, int b)
{
   return (!b) ? a : mcd(b, a % b);
}


int main()
{
    in >> T;
    while(T)
    {
        in >> a >> b;
        out << mcd(a, b);
        T--;
    }
    return 0;
}
