#include <iostream>
#include <fstream>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

int query,a,b;

int gcd(int a,int b){
    if(b == 0)
        return a;
    return gcd(b,a % b);
}

int main(){
    
    f >> query;
    
    while (query--) {
        f >> a >> b;
        g << gcd(a,b) << '\n';
    }
    
    f.close();
    g.close();
    return 0;
}
