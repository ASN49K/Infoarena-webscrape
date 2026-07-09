#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int t, a, b;

    fin >> t;
    for (int contor = 1; contor <= t; contor++)
    {
        fin >> a >> b;
        fout << gcd(a, b) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
