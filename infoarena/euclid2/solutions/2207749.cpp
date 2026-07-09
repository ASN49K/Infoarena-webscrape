#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        int x, y;
        fin >> x >> y;
        fout << gcd(x, y) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
