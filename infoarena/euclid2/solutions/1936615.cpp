#include <fstream>
using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

long long  N, X, Y;

long long CMMDC (long long x, long long y) {
    if (y == 0) {
        return x;
    }
    CMMDC (y, x % y);
}

int main()
{
    in >> N;
    for(; N; -- N) {
        in >> X >> Y;
        out << CMMDC (X,Y) <<'\n';
    }
    return 0;
}
