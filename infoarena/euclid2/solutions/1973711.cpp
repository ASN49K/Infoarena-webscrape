#include <iostream>
#include <fstream>
using namespace std;
int euclid (int a, int b) {
    if (!b) return a;
    return euclid(b, a % b);
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin >> n;
    int a, b;
    for (; n; --n) {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
    return 0;
}
