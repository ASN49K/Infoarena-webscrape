#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, x, y;

int main(){
    fin>>t;
    for (;t--;) {
        fin>>n;
        fin>>x;
        for (--n;n--;) {
            fin>>y;
            x^=y;
        }
        fout<<((x==0) ? "NU\n" : "DA\n");
    }

    return 0;
}
