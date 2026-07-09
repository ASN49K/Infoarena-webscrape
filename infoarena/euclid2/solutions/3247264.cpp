#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
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
    int n,a,b,c;
    fin >> n;
    for(int i=0; i<n; i++){
        fin >> a;
        fin >> b;
        if(a > b){
            c = a;
            a = b;
            b = c;
        }
        fout<<cmmdc(a,b)<<'\n';
    }
}