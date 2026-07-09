
//Arhiva Educationala - Algoritmul lui Euclid(pt. cmmdc)

#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
    if(b == 0){
        return a;
    }
    else{
        return cmmdc(b, a % b);
    }
}

int main()
{
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    long T;
    in >> T;

    while(--T >= 0){
        long long a;
        long long b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }
    return 0;
}
