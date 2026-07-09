#include <fstream>
using namespace std;

int cmmdc(int x, int y){
    int r;
    while (y != 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main(){
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");

    int n, x, i, y;

    fin >> n;

    for (i = 1; i <= n; i++) {
        fin >> x >> y;
        fout << cmmdc(x, y) << "\n";
    }

    return 0;
}
