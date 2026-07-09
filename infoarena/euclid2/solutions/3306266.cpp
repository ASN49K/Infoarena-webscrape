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
    int minValue = min(n, m);
    int maxValue = max(n, m);
    int remainder = maxValue % minValue;
    while (remainder != 0){
        maxValue = maxValue % minValue;
        remainder = maxValue;
        if (remainder == 0)
            break;
        if (minValue > maxValue)
        {
            swap(minValue, maxValue);
        }
    }
    cout << minValue << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int t = 1;
    cin >> t; // Uncomment for multiple test cases
    while (t--) {
        ReadData();
        Solve();
    }
    return 0;
}