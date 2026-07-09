#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t;

//ORIGINAL SHITE 100

int Euclid(int a, int b){
    if(!b) return a;
    return Euclid(b,a%b);
}

int main(){
    f>>t;
    for(t;t;--t){
        f>>a>>b;
        g<<Euclid(a,b)<<endl;
    }
return 0;
}
