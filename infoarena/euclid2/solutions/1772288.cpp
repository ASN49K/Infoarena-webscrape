#include <iostream>
#include <fstream>

int cmmdc(int a, int b){
    if(b > a) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return cmmdc(b, a % b);

}

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    int nr, a, b;
    fin >> nr;
    for (int i = 1; i <= nr; i++) {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
