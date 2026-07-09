#include <fstream>

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

int t,n,x,y;

int main () {

    fin>>t;
    while (t--) {
        fin>>n;
        x=0;
        while (n--) {
            fin>>y;
            x^=y;
        }
        fout<<(x?"DA":"NU")<<"\n";
    }
    return 0;
}

