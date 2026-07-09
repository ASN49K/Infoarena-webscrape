#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b) {
    if(a == 0) return b;
    return cmmdc(b % a, a);
}

int main()
{
    int n, a, b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> n;
    for(int i = 0; i < n; ++i) {
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}