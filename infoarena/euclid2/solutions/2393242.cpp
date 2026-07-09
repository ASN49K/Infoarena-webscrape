#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int a, b,nr,r;
    fin>>nr;
        while(nr!=0){
        fin>>a;
        fin>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        nr--;
        fout<<a<<"\n";
    }
}
