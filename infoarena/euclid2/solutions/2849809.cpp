#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,x,y,r;
int main() {
    fin>>t;
    while (t--) {
        fin>>x>>y;
        while (y!=0) {
            r=x%y;
            x=y;
            y=r;
        }
        fout<<x<<"\n";
    }
    return 0;
}
