#include <fstream>
using namespace std;

int a,b,t;

//ORIGINAL SHITE 100

int Euclid(int a, int b){
    if(!b) return a;
    return Euclid(b,a%b);
}

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(t;t;--t){
        f>>a>>b;
        g<<Euclid(a,b)<<endl;
    }
return 0;
}
