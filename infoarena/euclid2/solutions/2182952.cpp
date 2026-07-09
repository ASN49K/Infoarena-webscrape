#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int T,i,aux;
    f>>T;
    int perechi[3][100000];
    for(i=1;i<=T;i++)
        f>>perechi[1][i]>>perechi[2][i];
    for(i=1;i<=T;i++){
        while(perechi[1][i]%perechi[2][i]){
            aux=perechi[1][i]%perechi[2][i];
            perechi[1][i]=perechi[2][i];
            perechi[2][i]=aux;
        }
        o<<perechi[2][i]<<'\n';
    }
    f.close();
    o.close();
    return 0;
}
