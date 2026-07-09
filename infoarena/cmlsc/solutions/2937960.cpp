//
//  main.cpp
//  Cel mai lung subsir comun (infoarena)
//
//  Created by Andrei Bădulescu on 11.11.22.
//

//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N = 1024;

int a[N + 1], b[N + 1];

int results[N + 1][N + 1];
int n, m;

void resultBuilder(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    } else {
        if (a[i] == b[j]) {
            resultBuilder(i - 1, j - 1);
            cout << a[i] << ' ';
        } else if (results[i - 1][j] > results[i][j - 1]){
            resultBuilder(i - 1, j);
        } else {
            resultBuilder(i, j - 1);
        }
    }
}

int main() {
    cin >> m >> n;
    
    for (auto i = 1; i <= m; i++) {
        cin >> a[i];
    }
    
    for (auto i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    for (auto i = 1; i <= m; i++) {
        for (auto j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                results[i][j] = results[i - 1][j - 1] + 1;
            } else {
                results[i][j] = max(results[i - 1][j], results[i][j - 1]);
            }
        }
    }
    
    cout << results[m][n] << '\n';
    resultBuilder(m, n);
    return 0;
}
