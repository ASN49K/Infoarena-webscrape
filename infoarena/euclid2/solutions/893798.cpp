#include <iostream>
#include <fstream>
using namespace std;
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");

int main() {
    int64_t a,b,nr;
    fin>>nr;
    while(fin>>a>>b){
    while(b!=0){
    int64_t r=a%b;
    a=b;
    b=r;
    }
    gout<<a<<endl;
    }
}
