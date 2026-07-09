#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else return gcd((b % a), a);
}

int main()
{
    int T, a, b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        f >> a >> b;
        g << gcd(a, b) << endl;
    }

    f.close();
    g.close();

    return 0;
}
