#include <iostream>
#include <fstream>
using namespace std;
    ifstream fin("euclid2.in");
    ofstream gout("euclid2.out");

int main() {
    long long a,b,nr;
    fin>>nr;
    while(fin>>a>>b){
    while(b!=0){
    long long r=a%b;
    a=b;
    b=r;
    }
    gout<<a<<endl;
    }
}
