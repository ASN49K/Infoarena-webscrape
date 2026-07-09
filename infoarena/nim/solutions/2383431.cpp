#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t, n, v[10001], ok;

int main()
{
    f >> t;
    for(int i = 1; i <= t; ++i) {
        f >> n;
        for(int j = 1; j <= n; ++j)
            f >> v[j];
        ok = v[1];
        for(int j = 2; j <= n; ++j) {
            ok ^= v[j];
        }
        if(ok == 0) g << "NU \n";
        else g << "DA \n";
    }
    g.close();
    f.close();
    return 0;
}
