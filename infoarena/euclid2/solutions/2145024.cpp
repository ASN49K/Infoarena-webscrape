#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;

//ORIGINAL SHITE 100

int cmmdc(int x,int y){
    if(y==0) return x;
    return cmmdc(y,x%y);
}

int main(){
    f>>t;
    for(int i=t;i>=1;i--){
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
return 0;
}
