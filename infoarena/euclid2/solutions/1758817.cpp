#include <fstream>
using namespace std;
int main(){ifstream i("euclid2.in");ofstream o("euclid2.out");int n,a,b;i>>n;for(;n;--n){i>>a>>b;o<<__gcd(a,b)<<'\n';}}
