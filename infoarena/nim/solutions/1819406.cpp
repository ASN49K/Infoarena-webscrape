#include <cstdio>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int n, a, x, t, i;

int main(){
    scanf("%d", &t);
    fin >> t;
    for (; t; --t) {
        fin >> n;
        x = 0;
        for (i = 1; i <= n; ++i) {
            fin >> a;
            x = x ^ a;
        }
        if (x == 0) {
            fout << "NU\n";
        } else {
            fout << "DA\n";
        }
    }
    return 0;
}
