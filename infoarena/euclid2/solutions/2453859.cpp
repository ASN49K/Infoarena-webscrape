#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <map>

using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T;
    in >> T;

    while (T--){
        int a, b;
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }

    in.close();
    out.close();

    return 0;
}