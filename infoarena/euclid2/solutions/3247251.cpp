#include <iostream>
#include <fstream>

std::ifstream fin("D:\\C++ Projects\\Info Arena\\euclid2.in");
std::ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    while(a>0 && b>0){
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    if(a == 0)
        return b;
    else
        return a;
}

int main(){
    int n,a,b;
    fin >> n;
    for(int i=0; i<n; i++){
        fin >> a;
        fin >> b;
        std::cout<<cmmdc(a,b)<<'\n';
    }
}