#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q){
        int n;
        cin >> n;
        int x = 0;
        for(int i=0;i<n;++i){
            int l;
            cin >> l;
            x^=l;
        }
        cout << (x?"DA\n" : "NU\n");
        --q;
    }
    return 0;}
