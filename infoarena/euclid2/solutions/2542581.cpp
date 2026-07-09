#include <bits/stdc++.h>
using namespace std;


int main(){
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n, a, b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    cin.close(), cout.close();
}
