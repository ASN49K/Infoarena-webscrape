#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long cmmdc(long a, long b) {
    long r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int N;
    long x, y;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }
    return 0;
}
