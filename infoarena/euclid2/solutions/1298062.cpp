#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int n, a, b;

int main() {
    
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> a >> b,
        fout << cmmdc(a, b) << "\n";
    
    fin.close();
    fout.close();
    
    return 0;
}