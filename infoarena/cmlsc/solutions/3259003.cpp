#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, vector<int>> cel_mai_lung_subsir_comun(const vector<int>& subsir1, const vector<int>& subsir2) {
    // Create DP matrix
    vector<vector<int>> dp(subsir2.size() + 1, vector<int>(subsir1.size() + 1, 0));
    
    // Fill the DP matrix
    for(int i = 1; i <= subsir2.size(); i++) {
        for(int j = 1; j <= subsir1.size(); j++) {
            if(subsir1[j-1] == subsir2[i-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Get the actual subsequence
    vector<int> subsequence;
    int i = subsir2.size();
    int j = subsir1.size();
    
    while(i > 0 && j > 0) {
        if(subsir1[j-1] == subsir2[i-1]) {
            subsequence.push_back(subsir1[j-1]);
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    reverse(subsequence.begin(), subsequence.end());
    
    return {dp[subsir2.size()][subsir1.size()], subsequence};
}

pair<vector<int>, vector<int>> read_sequences(const string& filename) {
    ifstream fin(filename);
    int n, m;
    fin >> n >> m;  // Read sizes
    
    vector<int> subsir1(n);
    vector<int> subsir2(m);
    
    // Read first sequence
    for(int i = 0; i < n; i++) {
        fin >> subsir1[i];
    }
    
    // Read second sequence
    for(int i = 0; i < m; i++) {
        fin >> subsir2[i];
    }
    
    fin.close();
    return {subsir1, subsir2};
}

int main() {
    // Read input from file
    auto [subsir1, subsir2] = read_sequences("cmlsc.in");
    
    // Calculate result
    auto [length, subsequence] = cel_mai_lung_subsir_comun(subsir1, subsir2);
    
    // Write to file
    ofstream fout("cmlsc.out");
    fout << length << "\n";
    for(int element : subsequence) {
        fout << element << " ";
    }
    fout.close();
    
    cout << "Rezultatele au fost scrise in fisierul 'cmlsc.out'" << endl;
    
    return 0;
}