#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r= a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    ofstream cout("euclid2.out");
    ifstream cin("euclid2.in");
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        cout << gcd(x,y) << '\n';
    }
}
