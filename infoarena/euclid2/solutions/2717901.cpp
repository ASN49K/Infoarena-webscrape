#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b){
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    int t,a,b;
    in>>t;
    for(;t;t--){
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
}
