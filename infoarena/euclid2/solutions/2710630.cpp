#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int cmmdc(int x, int y) {
    while(y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int n, x, y;
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
