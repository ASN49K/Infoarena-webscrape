#include <bits/stdc++.h>

using namespace std;

const int NMax = 10005;

int t,n;
int a[NMax];

int main(){
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            sum ^= a[i];
        }
        if(sum == 0){
            cout << "NU\n";
        }else{
            cout << "DA\n";
        }
    }
    return 0;
}
