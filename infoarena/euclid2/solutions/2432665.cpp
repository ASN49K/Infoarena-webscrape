#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");



int main() {
    int tests;
    fin >> tests;
    while (tests) {
        int a, b;
        fin >> a >> b;

        while (a != 0 && b != 0)
        {
            if (a > b) a = a % b;
            else b = b % a;
        }

        if (a != 0) fout << a << '\n';
        else fout << b << '\n';
        tests--;
    }

    return 0;
}