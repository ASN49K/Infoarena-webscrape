#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
    long t,a,b,c,i;
    f>>t;
    for(i=0;i<t;i++) {
        f>>a>>b;
        while(b)
            c=a,a=b,b=c%a;
        g<<a<<'\n';
    }
}
