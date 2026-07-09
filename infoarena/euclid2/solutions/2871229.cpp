#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int cmmdc(int a, int b) {
    if (!b)
        return a;
    return cmmdc(b, a % b);
}

int main(){
    fin >> n;
    while (n--) {
        fin >> x >> y;
        fout << cmmdc(x, y) << '\n';
    }
    return 0;
}
