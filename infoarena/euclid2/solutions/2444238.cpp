#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t,x,y;

int cmmdc(int a,int b){
    if(b==0)    return a;
    return cmmdc(b,a%b);
}

int main(){
    fin>>t;
    for(int i=1;i<=t;++i){
        fin>>x>>y;
        fout << cmmdc(x,y) << "\n";
    }
    return 0;
}
