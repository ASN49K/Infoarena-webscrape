#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    ifstream cin ("nim.in");
    ofstream cout ("nim.out");
    cin >> t;
    for (int i=1, s = 0; i<=t; i++, s = 0){
        cin >> n;
        for (int j=1, a; j<=n; j++)
            cin >> a, s = (s^a);
        if (s) cout << "DA\n";
        else cout << "NU\n";
    }
    return 0;
}
