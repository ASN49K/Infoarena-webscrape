#include <fstream>
using namespace std;
int x,y,n,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int A, int B)
{
    if (B==0) return A;
    if (A > B) return gcd(A-B, B);
    return gcd(A, B-A);
}

int main(){
f>>n;
for(i=1;i<=n;i++){
f>>x>>y;
g<<gcd(x,y)<<"\n";
}
return 0;
}
