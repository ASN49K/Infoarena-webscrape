#include <iostream>
#include<fstream>
using namespace std;
unsigned cmmdc(unsigned a ,unsigned b){
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b;
    f >> T;
    for(int k=0;k<T;k++){
        f>>a>>b;
        g<<cmmdc(a,b)<< '\n';
    }
    return 0;
}
