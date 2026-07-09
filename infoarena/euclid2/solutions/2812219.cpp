#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void cmmdc(int a, int b) {
    if (a < b)swap(a, b);
    while (b > 0) {
        int aux = a % b;
        a = b;
        b = aux;
    }
    fout << a << "\n";
}
int main()
{
    int n, a, b;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> a >> b;
        cmmdc(a, b);
    }
}
