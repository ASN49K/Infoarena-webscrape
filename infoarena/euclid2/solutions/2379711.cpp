#include <fstream>
using namespace std;
int x,y,n;
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
while(n){
f>>x>>y;
g<<gcd(x,y)<<'\n';
n--;
}
}
