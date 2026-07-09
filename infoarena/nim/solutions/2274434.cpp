#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned short q;
    cin >> q;
    while(q){
        unsigned short n;
        cin >> n;
        int x = 0;
        for(int i=0;i<n;++i){
            unsigned short l;
            cin >> l;
            x^=l;
        }
        cout << (x?"DA\n" : "NU\n");
        --q;
    }
    return 0;}
