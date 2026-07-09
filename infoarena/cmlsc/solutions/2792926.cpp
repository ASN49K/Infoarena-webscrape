//
//  main.cpp
//  cmlsc
//
//  Created by Andrei Manaila on 02.11.2021.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

const int NMAX = 1025;
int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
stack<int> ans;

void Read() {
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> b[i];
    }
    fin.close();
}

void Solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i && j) {
        if (a[i] == b[j]) {
            ans.push(a[i]);
            i--;
            j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }
}

void Write() {
    ofstream fout("cmlsc.out");
    fout << ans.size() << "\n";
    while(!ans.empty()) {
        fout << ans.top() << " ";
        ans.pop();
    }
    fout << "\n";
    fout.close();
}

int main(int argc, const char * argv[]) {
    
    Read();
    Solve();
    Write();
    return 0;
}
