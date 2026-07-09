#include <array>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
 #include <bits/stdc++.h>
using namespace std;
 
constexpr int NMAX = 1031;
constexpr int alphabetSize = 257;
 
array<int,NMAX> v, w;
vector<int> lcs, lcsSize, orderedIdxs;
vector<int> bucket[alphabetSize];
 
ofstream out{"cmlsc.out"};
 
void printSolution (int idx, int val) {
    if (idx < 0 || 0 == val) return;
   
    int originalIdx = idx;
    for (; idx >= 0 && lcsSize[idx] != val - 1; --idx);
    printSolution (idx, val - 1);
    out << w[orderedIdxs[originalIdx]] << ' ';
}
 
int main() {
    int N, M;
 
    ifstream in{"cmlsc.in"};
 
    in >> N >> M;
    
    for (int i = 0; i < N; ++i) in >> v[i];
    for (int i = 0; i < M; ++i) {
        in >> w[i];
        bucket[w[i]].push_back(i);
    }
 
    for (auto& v: bucket) {
        sort (v.begin(), v.end(), [](int x, int y) {return x > y;});
    }
 
    for (const auto& x: v) {
        for (const auto& idx: bucket[x]) {
            orderedIdxs.push_back(idx);
 
            auto it = lower_bound(lcs.begin(), lcs.end(), idx);
 
            if (it == lcs.end()) {
              lcs.push_back(idx);
              lcsSize.push_back(lcs.size());
            }
            else {
              *it = idx;
              lcsSize.push_back(it - lcs.begin() + 1);
            }
        }
    }


    auto idx = max_element(lcsSize.begin(), lcsSize.end()) - lcsSize.begin();
 
    cerr << lcsSize[idx] << '\n';
    printSolution(idx, lcsSize[idx]);
 
    return 0;
}