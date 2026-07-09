
//Arhiva Educationala - Algoritmul lui Euclid(pt. cmmdc)

#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
    if(a == 1 || b == 1){
        return 1;
    }
    if(a != b){
        if(a > b){
            return cmmdc(a - b, b);
        }
        else{
            return cmmdc(a, b - a);
        }
    }
    else return a;

}

int main()
{
    std::ifstream in("euclid2.in");

    long T;
    in >> T;

    while(--T >= 0){
        long long a;
        long long b;
        in >> a >> b;
        std::cout << cmmdc(a, b) << '\n';
    }
    return 0;
}
