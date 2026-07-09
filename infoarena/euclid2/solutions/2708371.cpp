#include <fstream>

using namespace std;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n; fin >> n;
    for (int i=0; i<n; i++) {
        int a, b; fin >> a >> b;
        if (a > b) swap(a, b);
        while (a != 0) {
            b %= a;
            swap(a, b);
        }
        fout << b <<     '\n';
    }
}