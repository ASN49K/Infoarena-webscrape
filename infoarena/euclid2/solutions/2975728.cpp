#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n;

int euclid(int a, int b){
    if(b == 0) return a;
    return euclid(b, a % b);
}

int main() {
    in >> n;
    for(int i = 0;i < n;i++){
        int a, b;
        in >> a >> b;
        out << euclid(a, b) << '\n';
    }
    return 0;
}
