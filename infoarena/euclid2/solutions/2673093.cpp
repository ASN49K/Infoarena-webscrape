#include <fstream>

using namespace std;

void cmmdc(int a, int b, int& c){
    int aux;
    while(a!=0 && b!=0){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }

    if(a==0){
        c = b;
    }else{
        c = a;
    }
}

int main(){
    int perechi, a, b, div;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> perechi;
    for(int i=0;i < perechi;i++){
        f >> a >> b;
        cmmdc(a, b, div);
        g << div << "\n";
    }
}
