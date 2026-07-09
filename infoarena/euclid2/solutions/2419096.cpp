#include <fstream>
using namespace std;
unsigned int gcd(unsigned int u, unsigned int v)
{
    unsigned int shift = 0;
    if (u == 0) return v;
    if (v == 0) return u;
    while (((u | v) & 1) == 0) {
        shift++;
        u >>= 1;
        v >>= 1;
    }
    while ((u & 1) == 0)
        u >>= 1;
    do {
        while ((v & 1) == 0)
            v >>= 1;
        if (u > v) {
            unsigned int t = v; v = u; u = t; // Swap u and v.
        }
        v -= u;
    } while (v != 0);
    return u << shift;
}
int main(){
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned int a,b,i,n;
fin>>n;
for(i=1;i<=n;i++){
    fin>>a>>b;
    fout<<gcd(a,b)<<"\n";
}
return 0;
}
