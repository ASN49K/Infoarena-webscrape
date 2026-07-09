#include <iostream>
#include <fstream>

using namespace std;

int n, x, y;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main()
{
    fin >> n;
    while (n) {
        fin >> x >> y;
        n--;
        fout << GCD(x, y) << "\n";
    }
    return 0;
}
