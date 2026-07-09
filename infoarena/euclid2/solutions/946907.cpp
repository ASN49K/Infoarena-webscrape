#include <cstdlib>
#include <fstream>


using namespace std;


inline int gcd(int x, int y)
{
    return !y ? x : gcd(y, x % y);
}

int main()
{
    int T, a, b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    for(in >> T; T; --T)
    {
        in >> a >> b;
        out << gcd(a, b) << '\n';
    }

    return EXIT_SUCCESS;
}
