#include <fstream>
int cmmdc(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    std::ifstream fin ("euclid2.in");
    std::ofstream fout("euclid2.out");
    int t, a, b;
    fin >> t;
    for (int i = 0; i < t; ++i) {
        fin >> a >> b;
        fout << cmmdc(a, b) << '\n';
    }

    return 0;
}
