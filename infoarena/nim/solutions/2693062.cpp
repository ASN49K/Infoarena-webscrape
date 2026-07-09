//ALEXANDRU MICLEA

#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <time.h>
#include <iomanip>
#include <deque>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <stack>
#include <bitset>
#include <random>
#include <chrono>
#include <assert.h>

using namespace std;
using ll = long long;

#include <fstream>
//ifstream cin("input.in"); ofstream cout("output.out");
ifstream cin("nim.in"); ofstream cout("nim.out");

//VARIABLES

int v[10005];

//FUNCTIONS



//MAIN

int main() {

    int t; cin >> t;
    while (t--) {
        int xorsum = 0;

        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            xorsum ^= v[i];
        }

        if (xorsum) cout << "DA\n";
        else cout << "NU\n";
    }

    return 0;
}