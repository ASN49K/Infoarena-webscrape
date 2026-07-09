#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b){
    int aux;
    while(b){
        aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}
int main(){
    int T,a,b;
    fin>>T;
    for(int i=1;i<=T;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
