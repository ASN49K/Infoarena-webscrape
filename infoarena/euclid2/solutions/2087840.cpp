#include <iostream>
#include <fstream>
using namespace std;
int T,a,b,d;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(){
    f>>T;
    while(T!=0){
        f>>a>>b;
        if(a<b){
            d=a;
            while(a%d!=0 || b%d!=0)d=d/2;
        }
        if(b<a){
            d=b;
            while(a%d!=0 || b%d!=0)d=d/2;
        }
        g<<d<<endl;
        T--;
    }
    f.close();
    g.close();
return 0;
}
