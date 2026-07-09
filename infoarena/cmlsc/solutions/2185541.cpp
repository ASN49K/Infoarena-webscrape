#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int T,i,a,b,aux;
    f>>T;
    for(i=1;i<=T;i++){
        f>>a>>b;
        while(a%b){
            aux=a%b;
            a=b;
            b=aux;
        }
        o<<b<<'\n';
    }
    f.close();
    o.close();
    return 0;
}
