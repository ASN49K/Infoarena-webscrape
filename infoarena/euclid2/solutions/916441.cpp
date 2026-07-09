#include <fstream>
using namespace std; ifstream f("euclid2.in"); ofstream g("euclid2.out");
long long euclid(long long a,long long b,long long r)
 { if (r==0) {return b;} else {b=euclid(b,r,a%b); return b;} }
int main() { int i,n; long long a,b;
  f>>n; for (i=1;i<=n;i++) {f>>a>>b; g<<euclid(a,b,a%b)<<'\n'; } }
