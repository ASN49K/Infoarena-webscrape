#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y) {
    while (y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }
    return 0;
}
