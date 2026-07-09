#include <fstream>
using namespace std;
int a,b,n;

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    while (n--) {
        fin>>a>>b;
        while (b) {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
    return 0;
}
