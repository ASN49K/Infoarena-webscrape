#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b){
    if (!b) return a;
    return cmmdc(b,a%b);
}
int main(){
    int t,a,b;
    in>>t;
    for(;t;t--){
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;
    }
}
