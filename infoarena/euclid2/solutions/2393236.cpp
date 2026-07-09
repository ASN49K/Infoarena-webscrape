#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int a,b,rez=2131,nr;
    fin>>nr;
    while(nr!=0){
        fin>>a>>b;
        int aa=a,bb=b;
        while(a%rez!=0 && b%rez!=0){
            rez = aa % bb;
            aa = bb;
            bb = rez;
        }
        nr--;
        fout<<rez<<"\n";
    }
}
