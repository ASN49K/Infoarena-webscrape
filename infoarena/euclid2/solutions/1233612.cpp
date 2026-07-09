#include <fstream>
using namespace std;

int main(){
    ifstream fin ("euclid.in");
    ofstream fout ("euclid.out");

    int n, x, i, y, r;

    fin >> n;

    for (i = 1; i <= n; i++) {
        fin >> x >> y;
        while (y != 0 ) {
            r = x % y;
            x = y;
            y = r;
        }
        fout << x << "\n";
    }

    return 0;
}
