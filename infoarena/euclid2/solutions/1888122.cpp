#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,i;
int cmmdc(int a, int b){
    if(b==0)
        return a;
    else
        cmmdc(b, a%b);
}
int main(){
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }


    return 0;
}
