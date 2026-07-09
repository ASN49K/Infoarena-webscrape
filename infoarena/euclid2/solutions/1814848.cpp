#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd (unsigned int a,unsigned int b) {
    if (!b) return a;
    return gcd (b,a%b);
}

int main()
{
    unsigned int a, b, t, aux;
    fin>>t;
    for (unsigned int i=1; i <= t; i++) {
        fin >> a >> b;
        fout << gcd(a,b) << '\n';
    }
    return 0;
}
