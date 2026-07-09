//
//  main.cpp
//  Cel mai lung subsir comun (infoarena)
//
//  Created by Andrei Bădulescu on 25.01.23.
//

//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

const int N = 1024;

int partials[N + 1][N + 1];
int a[N + 1], b[N + 1];
int n, m;

void reversePrint(int x, int y) {
    if (x && y) {
        if (partials[x][y - 1] == partials[x][y]) {
            reversePrint(x, y - 1);
        } else {
            if (partials[x - 1][y] == partials[x][y]) {
                reversePrint(x - 1, y);
            } else {
                reversePrint(x - 1, y - 1);
                cout << a[x] << ' ';
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (auto i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (auto i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (auto i = 1; i <= n; i++) {
        for (auto j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                partials[i][j] = partials[i - 1][j - 1] + 1;
            } else {
                partials[i][j] = max(partials[i - 1][j], partials[i][j - 1]);
            }
        }
    }

    cout << partials[n][m] << '\n';
    reversePrint(n, m);
    return 0;
}
