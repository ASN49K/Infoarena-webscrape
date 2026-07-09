#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;

int cmmdc(int a, int b){
    if(b==0) return a;
    return cmmdc(b,a%b);
}

int main(){
    f>>t;
    for(int i=t;i>=1;i--){
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
  return 0;
}
