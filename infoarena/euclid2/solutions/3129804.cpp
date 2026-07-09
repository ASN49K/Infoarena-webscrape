#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int x, int y) {
    int i;
    while(b != 0) {
        i = a % b;
        a = b;
        b = i;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y;
    for(int i = 0; i < n; i++) {
        fin>>x>>y;
        fout<<cmmdc(x, y)<<endl;
    }
    return 0;
}