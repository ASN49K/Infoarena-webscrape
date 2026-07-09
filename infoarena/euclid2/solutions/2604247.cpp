#include <iostream> 
#include <fstream>

int gcd(int a, int b) { 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
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
  