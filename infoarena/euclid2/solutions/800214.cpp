#include <fstream>
using namespace std;

template<class T> T gcd(T a, T b){  //T - tipuri integrale
    T temp;
    if(a>b){ temp=a; a=b; b=temp; }
    while(temp=a%b){
        a=b;
        b=temp;
    }
    return b;
}

int main(){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    unsigned int T;
    fin>>T;
    while(T--){
        unsigned int a,b;
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
}
