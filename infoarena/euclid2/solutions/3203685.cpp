#include <fstream>
#include <cmath>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int n, a, b, res;

void euclid(int a, int b) {
    if(b == 0)
        return a;
    return euclid(b, a % b);
}

int main() {
    fin >> n;
    while(n--) {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}
