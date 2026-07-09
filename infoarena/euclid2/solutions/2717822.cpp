#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
    int t,a,b;
    in>>t;
    for(;t;t--){
        in>>a>>b;
         int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
        out<<b<<endl;
    }
}
