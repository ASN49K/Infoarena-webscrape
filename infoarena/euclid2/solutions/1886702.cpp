#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int cmmdc(int a,int b){
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}
int main(){
    fin>>t;
    int a,b;
    while(t--){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    fout.close();
    fin.close();
    return 0;
}
