#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    int t, a, b;
    for(fin >> t; t; --t) {
        fin >> a >> b;
        while(a && b) {
            if(a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        fout << max(a, b);
    }
}
