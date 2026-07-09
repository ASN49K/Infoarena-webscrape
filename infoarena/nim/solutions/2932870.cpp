#include <fstream>

int main(){
    std::ifstream in("nim.in");
    std::ofstream out("nim.out");

    std::size_t t;
    in >> t;

    for(int ti = 0 ; ti < t; ++ti){
        std::size_t n, xor_sum = 0;
        in >> n;
        for(int i = 0; i < n; ++i){
            std::size_t a;
            in >> a;
            xor_sum ^= a;
        }
        if(xor_sum > 0){
            out << "DA\n";
        }else{
            out << "NU\n";
        }
    }
}