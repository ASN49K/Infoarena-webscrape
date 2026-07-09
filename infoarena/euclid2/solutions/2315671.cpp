#include <fstream>
#include <iostream>
using namespace std;
int euclid(int a, int b);
int a, b, t;
int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> t;
    for (int i = 0; i < t; ++i) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}

int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}