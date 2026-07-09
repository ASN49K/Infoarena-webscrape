#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
void cmmdc(int a,int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    out<<a<<'\n';
}
int main(){
    int n,a,b,r;
    in>>n;
    while(n--){
        in>>a>>b;
        cmmdc(a,b);
    }
    return 0;
}