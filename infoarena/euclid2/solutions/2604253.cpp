#include <iostream> 
#include <fstream>

int gcd(int a, int b) { 
    if (!b) 
        return a; 
    return gcd(b, a % b); 
} 

int main() { 
    std::ifstream in_file {"euclid2.in"};
    std::ofstream out_file {"euclid2.out"};
    
    int T, a, b;
    in_file >> T;
    
    for(int i{0}; i < T; ++i) {
        in_file >> a >> b;
        out_file << gcd(a, b) << std::endl;
    }
    return 0; 
}