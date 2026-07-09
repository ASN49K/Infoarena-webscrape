#include <bits/stdc++.h>
using namespace std;
const char* IN = "euclid2.in";
const char* OUT = "euclid2.out";

namespace Math {
    int cmmdc(int a,int b){
        return (a == 0) ? b : cmmdc(b%a,a);
    }
}

int a,b,t;
int main(void){
    ifstream cin(IN);
    ofstream cout(OUT);
    cin>>t;
    while(t--){
        cin >> a >> b;
        cout << Math::cmmdc(a,b) << "\n";
    }
    return 0;
}
