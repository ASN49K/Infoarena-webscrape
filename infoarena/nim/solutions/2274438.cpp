#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    short q;
    cin >> q;
    while(q){
        short n;
        cin >> n;
        int x = 0;
        for(short i=0;i<n;++i){
            int l;
            cin >> l;
            x^=l;
        }
        cout << (x?"DA\n" : "NU\n");
        --q;
    }
    return 0;}
