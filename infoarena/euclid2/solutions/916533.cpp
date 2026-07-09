#include <fstream>
using namespace std; ifstream f("euclid2.in"); ofstream g("euclid2.out");
int euclid(int a,int b,int r) {if (r==0) {return b;} else {return euclid(b,r,b%r);} };
int main() {int n,a,b,i; f>>n; for (i=1;i<=n;i++) {f>>a>>b; g<<euclid(a,b,a%b)<<'\n';}; }
