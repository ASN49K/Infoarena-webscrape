#include <bits/stdc++.h>
using namespace std;


int main(void){
    ofstream cout("euclid2.out");
    ifstream cin("euclid2.in");
    int T;
    cin >> T;
    while(T--){
        int x, y;
        cin >> x >> y;
        cout << __gcd(x,y) << '\n';
    }
}
