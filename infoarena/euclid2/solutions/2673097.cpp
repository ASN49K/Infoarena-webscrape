#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void cmmdc(long a, long b){
    while(a!=0 && b!=0){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }

    if(a==0){
        g << b << "\n";
    }else{
        g << a << "\n";
    }
}

int main(){
    int perechi;
    long long a, b;

    f >> perechi;
    for(int i=0;i < perechi;i++){
        f >> a >> b;
        cmmdc(a, b);
    }
}
