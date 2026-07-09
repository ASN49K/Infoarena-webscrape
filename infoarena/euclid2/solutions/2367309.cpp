#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & -x)

using namespace std;

ifstream in("a.in");
ofstream out("a.out");

int euclid(int a, int b) {
    while(b) {
        int c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main() {

    int ntests;
    in >> ntests;
    while(ntests --) {
        int a, b;
        in >> a >> b;
        out << euclid(a, b) << "\n";
    }

    return 0;
}
