#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b){
    int t;
    while(b){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int n, a, b;
    f >> n;
    for(int i=1; i<=n; i++){
        f >> a >> b;
        g << gcd(a, b)<<'\n';
    }
    return 0;
}
