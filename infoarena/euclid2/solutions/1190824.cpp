#include <fstream>
using namespace std;
int t, a, b, r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
    fin>>t;
    for (;t--;) {
        fin>>a>>b;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<"\n";
    }

    return 0;
}
