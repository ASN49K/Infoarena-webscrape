#include <iostream>
#include <fstream>

using namespace std;
int findGCD (int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    fstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t;
    fin >> t;

    for (int test = 1; test <= t ; ++test) {
        int a, b;
        fin >> a >> b;
        fout << findGCD(a, b) << "\n";
    }
    return 0;
}
