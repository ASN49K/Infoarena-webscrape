#include <iostream>
#include <fstream>
using namespace std;

int t,a,b,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int x,int y){
    while(y){
        r=x%y;
        x=y;y=r;
    }
    return x;
}

int main(){
    fin>>t;
    for(int i=1;i<=t;++i){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }


    return 0;
}
