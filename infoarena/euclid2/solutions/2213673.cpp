#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    while (b) {
        int c;
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main()
{
    int a, b, T;
    fin >> T;
    while (T) {
        fin >> a >> b;
        fout << cmmdc(a,b) << "\n";
        T--;
    }
}
