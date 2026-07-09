#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b==0) {
        return a;
    }
    else{
        gcd(b,a%b);
    }
}

int main() {

    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");

    int n;
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}
