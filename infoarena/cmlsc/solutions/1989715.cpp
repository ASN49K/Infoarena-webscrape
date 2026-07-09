#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    short n, m, *a, b, *ab, *c, max_ab, i, j;
    fin >> n >> m;
    a = new short[n+1];
    ab = new short[(n+1) * (m+1)];
    ab[0] = 0;
    for(i = 1; i <= n; ++i) {
        fin >> a[i];
        ab[i*(m+1)] = 0;
    }
    for(j = 1; j <= m; ++j) {
        ab[j] = 0;
        fin >> b;
        for(i = 1; i <= n; ++i) {
            (b == a[i])?(ab[i*(m+1) + j] = ab[(i-1)*(m+1) + j-1] + 1):(ab[i*(m+1) + j] = max(ab[(i-1)*(m+1) + j],ab[i*(m+1) + j-1]));
        }
    }

    max_ab = ab[(m+1)*(n+1) - 1];
    fout << max_ab << "\n";

    c = new short[max_ab];
    for(i = n, j = m; max_ab; --i) {
        if(ab[i*(m+1) + j] > ab[(i-1)*(m+1) + j-1]) {
            c[--max_ab] = a[i];
            --j;
        }
    }
    for(i = 0; i < ab[(m+1)*(n+1) - 1]; ++i) {
        fout << c[i];
    }

}
