#include <fstream>
using namespace std;
int x,y,n,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int A, int B)
{
    if (!B) return A;
    return gcd(B,A%B);
}

int main(){
f>>n;
for(i=1;i<=n;i++){
f>>x;
f>>y;
g<<gcd(x,y)<<"\n";
}
return 0;
}
