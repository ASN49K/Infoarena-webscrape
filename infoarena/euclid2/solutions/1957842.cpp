#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int cmmdc(int a,int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
void solve(){
    int a,b;
    for(int i=1;i<=t;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
}
int main(){
    fin>>t;
    solve();
    return 0;
}
