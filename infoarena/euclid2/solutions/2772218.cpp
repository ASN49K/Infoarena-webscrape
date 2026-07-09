#include <fstream>

using namespace std;
int cmmdc(int a,int b){
    int aux;
    while(b!=0){
        aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t,i,a,b;
    fin>>t;
    for(i=1;i<=t;++i){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
