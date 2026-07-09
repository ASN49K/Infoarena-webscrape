#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned cmmdc(unsigned a ,unsigned b){
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main(){
    int T,a,b;
    f >> T;
    for(int k=0;k<T;k++){
        f>>a>>b;
        g<<cmmdc(a,b)<< endl;
    }
    return 0;
}
