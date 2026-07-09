#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

int cmdc(int a, int b){
    if(b == 0)
        return a;
    return cmdc(b,a%b);
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
        fout<<cmdc(a,b)<<'\n';
    }
}