#include <bits/stdc++.h>

using namespace std;

int t=0, n=0, a=0, xorsum=0;

int main(){
    ifstream f("nim.in");
    ofstream g("num.out");
    f>>t;
    while(t--){
        f>>n;
        xorsum = 0;
        for(int i=1; i<=n; ++i){
            f>>a;
            xorsum = xorsum ^ a;
        }
        if(xorsum) cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
