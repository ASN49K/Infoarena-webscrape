#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int b,int a){

    if(!a) return b;
    return cmmdc(a,b%a);
}
int main(){
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int T,i,a,b;
    f>>T;
    for(i=1;i<=T;i++){
        f>>a>>b;
        o<<cmmdc(a,b)<<"\n";
    }
    f.close();
    o.close();
}
