#include <fstream>
#include <cstdlib>

using namespace std;
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int T, a, b;
    ifstream in{"euclid2.in"};
    ofstream out{"euclid2.out"};

    for(in >> T; T; --T)
    {
	in >> a >> b;
	out << gcd(a, b) << '\n';
    }

    return EXIT_SUCCESS;
}
