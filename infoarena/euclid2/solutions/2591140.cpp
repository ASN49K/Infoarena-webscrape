#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(unsigned int a, unsigned int b){
    if(b==0) return a;
    else{
        cmmdc(b, a%b);
    }
}

int main(){
    unsigned int T, a, b;
    fin>>T;

    for(int i=1;i<=T;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b);
        fout<<"\n";
    }

    fout.close();
    return 0;
}
