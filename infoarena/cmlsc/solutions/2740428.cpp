//
// Created by Radu Vrinceanu on 12.04.2021.
//

#ifndef OLIMPIADA_CMLSC_H
#define OLIMPIADA_CMLSC_H

#endif //OLIMPIADA_CMLSC_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const unsigned int MAX_SIZE = (1 << 10) + 1;
unsigned short m, n, DP[MAX_SIZE][MAX_SIZE], first[MAX_SIZE], second[MAX_SIZE];
vector<unsigned short> solution;

int main() {
    fin >> m >> n;
    for (unsigned int i = 1; i <= m; i++)
        fin >> first[i];
    for (unsigned int i = 1; i <= n; i++)
        fin >> second[i];
    fin.close();

    for (unsigned int i = 1; i <= m; i++) {
        for (unsigned int j = 1; j <= n; j++) {
            if (first[i] == second[j]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    for (short i = m, j = n; i; ) {
        if (first[i] == second[j]) {
            solution.push_back(first[i]);
            --i, --j;
        }
        else if (DP[i - 1][j] < DP[i][j - 1]) {
            --j;
        }
        else {
            --i;
        }
    }

    fout << DP[m][n] << '\n';
    for (unsigned short x : solution) {
        fout << x << ' ';
    }
    fout.close();

    return 0;
}
