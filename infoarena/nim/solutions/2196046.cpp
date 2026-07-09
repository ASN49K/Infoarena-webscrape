#include <bits/stdc++.h>
using namespace std;
int t, n, a, s;

int main(){
    ifstream cin ("nim.in");
    ofstream cout ("nim.out");
    cin >> t;
    while(t--){
        cin >> n;
        s = 0;
        while (n--){
            cin >> a;
            s ^= a;
        }
        cout << (s ? "DA\n" : "NU\n");
    }
    return 0;
}
