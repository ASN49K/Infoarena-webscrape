#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,a,s,i,n;

int main() {
    f >> t;
    for (;t>0;t--) {
        f >> n;s=0;
        for (i=1;i<=n;i++) {
            f >> a;
            s^=a;
        }
        if (s) g << "DA" << '\n';
            else g << "NU" << '\n';
    }
    f.close();g.close();
    return 0;
}
