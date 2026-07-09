#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b;

int euclid(int a, int b) {
    if (!b)
        return a;
    else
        return euclid(b, a % b);
}

int main() {
    fin >> n;
    while (n--) {
        fin >> a >> b;
        fout << euclid(a, b) << "\n";
    }
}
