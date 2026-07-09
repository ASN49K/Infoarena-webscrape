#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
int euclid(int a,int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    fin>>t;
    for(int i=1;i<=t;i++){
            fin>>a>>b;
            fout<<euclid(a,b)<<"\n";
    }
    return 0 ;
}
