#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <string>
#include <climits>
#include <cstring>

#define LL long long
#define billion 1000000000
const LL mod = 998244353;
const double pi = 3.14159265359;

#define maxn 2005

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

LL gcd(LL a, LL b) {
    LL r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() 
{
    int t;
    fin >> t;
    while (t--) {
        LL a, b;
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}