#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,m;
int cmmdc(int a,int b){
     while(b!=0){
        int r=a%b;
        a=b;
        b=r;
     }
     return a;
}
int main(){
    int q;
    fin>>q;
    while(q--){
    fin>>n>>m;
    fout<<cmmdc(n,m)<<'\n';
    }
 return 0;
}
