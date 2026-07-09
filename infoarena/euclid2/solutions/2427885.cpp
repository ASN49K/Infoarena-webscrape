#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b){
if (!b)
    return a;
else
    return cmmdc(b, a%b);}
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int main(){
int T,a,b;
fi>>T;
for (int i=1; i<=T; i++){
fi>>a;
fi>>b;
fo<<cmmdc(a,b)<<endl;}
    return 0;
}
