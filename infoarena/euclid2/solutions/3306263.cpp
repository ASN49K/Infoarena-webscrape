#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>

using namespace std;

#define ll long long

// Global variables
int n, m = 0;

void ReadData() {
   cin >> n >> m;
}

void Solve() {
    // TODO: Implement problem solution here
    int maxDivisor = 1;
    int div = 2;
    while (div <= min(n, m)) {
        if (n % div == 0 && m % div == 0)
        {
            maxDivisor = max(maxDivisor, div);
        }
        div++;
    }
    cout << maxDivisor << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t; // Uncomment for multiple test cases
    while (t--) {
        ReadData();
        Solve();
    }
    return 0;
}