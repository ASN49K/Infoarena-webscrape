#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b);

int n, a, b;
int main()
{
    fin >> n;
    while (n--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}

int gcd(int a, int b)
{
    while (a > 0)
    {
        int temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}