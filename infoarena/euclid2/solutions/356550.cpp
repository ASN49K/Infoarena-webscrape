#include <fstream>
using namespace std;
long int i,j,k,l,T;
int main () {
    ifstream f; ofstream g;
    f.open ("euclid2.in"); g.open ("euclid2.out");
    f>>T;
    for (i=1; i<=T; i++) {
        f>>j>>k;
        while (k) {
              l=k;
              k=j%k;
              j=l;
        }
        g<<j<<"\n";
    }
    f.close (); g.close ();
    return 0;
}
