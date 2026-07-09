#include <bits/stdc++.h>
using namespace std;

int t,n,s;

int main(){
    ifstream cin ("nim.in");
    ofstream cout ("nim.out");
    cin>>t;
    for (int j=1; j<=t; j++){
        cin>>n;
        s=0;
        for (int i=1; i<=n; i++){
            int a; cin>>a; s=(s^a);
        }
        if (s) cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
