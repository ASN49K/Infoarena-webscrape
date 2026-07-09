#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int main(){
    int t;
    f >> t;
    while(t--){
        int n;
        f >> n;
        int xorsum = 0;
        while(n--){
            int x;
            f >> x;
            xorsum ^= x;
        }

        g << (xorsum == 0? "NU\n" : "DA\n");
    }
    return 0;
}
