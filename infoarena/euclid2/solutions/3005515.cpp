#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int r;
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n, x, y;
    fin >> n;
    while (n--)
    {
        fin >> x >> y;
        fout << gcd(x, y) << "\n";

    }
    return 0;
}