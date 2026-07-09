#include <fstream>

//2<=a,b deci nu ma ocup de cazuri speciale
unsigned gcd(unsigned a, unsigned b){
    unsigned temp;

    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }

    return a;
}


int main(){
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    unsigned T;
    fin>>T;

    for(;T>0;--T){
        unsigned a,b;
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
}
