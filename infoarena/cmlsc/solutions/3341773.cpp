#include <bits/stdc++.h>

using namespace std;

int main() {
    // Adding file I/O as per your request
    if (fopen("cmlsc.in", "r")) {
        freopen("cmlsc.in", "r", stdin);
        freopen("cmlsc.out", "w", stdout);
    }

    // Speed up standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Map: Key = value from first array, Value = vector of its indices
    unordered_map<int, vector<int>> g;
    
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        // Using push_back on the map's vector value
        g[v].push_back(i);
    }

    vector<int> numere;
    for (int i = 1; i <= m; i++) {
        int v;
        cin >> v;
        // Using .count() to check if the value exists in the first array
        if (g.count(v)) {
            numere.push_back(v);
            
            /* NOTE: If you want to simulate LCS logic, 
               you'd usually need to track the 'i' index 
               from the map to ensure it's strictly increasing.
            */
        }
    }

    // Print total count
    cout << numere.size() << '\n';
    
    // Print the numbers found
    for (int i = 0; i < numere.size(); i++) {
        cout << numere[i] << (i == numere.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}