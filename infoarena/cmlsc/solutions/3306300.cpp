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

void ReadData() {
   cin >> m >> n;
   A.resize(m);
   B.resize(n);

   for(int i = 0; i < m; i++ ) {
        cin >> A[i];
   }
   for(int i = 0; i < n; i++ ) {
        cin >> B[i];
   }
}

vector<int> Solve(const vector<int> &a, const vector<int> &b, vector<int> result) {
    if (a.empty() || b.empty()) return result;

    if(a[0] == b[0]){
        result.push_back(a[0]);
        if(a.size() == 1 && b.size() == 1)
            return result;
        return Solve(vector<int>(a.begin() + 1, a.end()), vector<int>(b.begin() + 1, b.end()), result);
    }
    if (a.size() == 1)
        return Solve(a, vector<int>(b.begin() + 1, b.end()), result);
    if (b.size() == 1)
        return Solve(vector<int>(a.begin() + 1, a.end()), b, result);

    vector<int> right = Solve(a, vector<int>(b.begin() + 1, b.end()), result);
    vector<int> left = Solve(vector<int>(a.begin() + 1, a.end()), b, result);  
    if(right.size() > left.size())
        return right;
    else
        return left;
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
        vector<int> empty;
        vector<int> result = Solve(A, B, empty);
        for(int x : result){
            cout << x << " ";
        }
    }
    return 0;
}