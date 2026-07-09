#include <fstream>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

typedef long long ll;

ll n,a,b;

ll gcd(ll a,ll b){
    return (b == 0 ? a : gcd(b,a % b));
}

int main(){
    
    f >> n;
    
    while(n--){
        f >> a >> b;
        g << gcd(a,b) << '\n';
    }
    
    return 0;
}
