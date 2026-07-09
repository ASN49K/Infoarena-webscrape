#include <fstream>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int cmmdc(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int N, a, b;
    fin >> N;
    for (int i = 0; i < N; ++i) {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
