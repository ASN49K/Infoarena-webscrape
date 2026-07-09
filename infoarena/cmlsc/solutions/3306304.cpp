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
int m, n = 0;
vector<int> A, B;
vector<vector<vector<int>>> dp;

void ReadData() {
   cin >> m >> n;
   A.resize(m);
   B.resize(n);
   dp.resize(m, vector<vector<int>>(n)); 
   for(int i = 0; i < m; i++ ) {
        cin >> A[i];
   }
   for(int i = 0; i < n; i++ ) {
        cin >> B[i];
   }
}

vector<int> Solve(const vector<int> &a, const vector<int> &b, int i, int j) {
    if (i == a.size() || j == b.size())
        return {};
        
    if(!dp[i][j].empty())
        return dp[i][j];

    if (a[i] == b[j]) {
        vector<int> res = Solve(a, b, i+1, j+1);
        res.insert(res.begin(), a[i]);
        dp[i][j] = res;
        return res;
    } else {
        vector<int> left = Solve(a, b, i+1, j);
        vector<int> right = Solve(a, b, i, j+1);
        if (left.size() > right.size())
            dp[i][j] = left;
        else    
            dp[i][j] = right;
        return (left.size() > right.size()) ? left : right;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) {
        ReadData();
        vector<int> result = Solve(A, B, 0, 0);
        cout << result.size() << "\n";
        for(int x : result){
            cout << x << " ";
        }
    }
    return 0;
}