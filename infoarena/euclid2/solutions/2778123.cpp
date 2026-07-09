#include <bits/stdc++.h>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc(int a, int b){
    while(b!=0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    int T, a, b;
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> a >> b;
        cout << cmmdc(a,b) << '\n';
    }
    return 0;
}