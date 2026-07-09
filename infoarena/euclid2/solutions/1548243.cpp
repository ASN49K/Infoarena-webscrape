#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main () {
    int n;
    fin>>n;

    int a,b;
    for (int i=1; i<=n; i++) {
        fin>>a>>b;
        while (b!=0) {
            a=a%b;
            int x=a;
            a=b;
            b=x;
        }
        fout<<a<<"\n";
    }

    fout<<"\n";
    return 0;
}
