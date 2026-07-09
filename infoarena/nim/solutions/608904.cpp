#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,ti,x,i,sumax,n;

int main() {
    f >> t;
    for (ti=1;ti<=t;ti++) {
        f >> n;sumax=0;
        for (i=1;i<=n;i++) {
            f >> x;
            sumax^=x;
        }
        if (sumax>0) g << "DA" << '\n';
               else  g << "NU" << '\n';
    }
    f.close();g.close();
    return 0;
}
