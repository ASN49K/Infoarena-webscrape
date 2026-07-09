
//Arhiva Educationala - Algoritmul lui Euclid(pt. cmmdc)

#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
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
