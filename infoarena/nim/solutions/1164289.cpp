#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,n,i,k,nr;
int main() {
    f>>t;
    while(t--) {
        f>>n>>nr;
        for(i=1;i<n;i++) {
            f>>k;
            nr^=k;
        }
        if(nr==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }
    return 0;
}
