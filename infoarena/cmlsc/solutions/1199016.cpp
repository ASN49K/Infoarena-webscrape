#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 1024

int first[MAX_SIZE];
int second[MAX_SIZE];
int memo[MAX_SIZE][MAX_SIZE];

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    
    int size_first, size_second;
    in >> size_first >> size_second;
    for (int i = 1; i <= size_first; i++) {
        in >> first[i];
        memo[i][0] = 0;
    } 
    memo[size_first][0] = 0;
    for (int i = 1; i <= size_second; i++) {
        in >> second[i];
        memo[0][i] = 0;
    }
    memo[0][size_second] = 0; 
    memo[0][0] = 0;
    for (int i = 1; i <= size_first; i++) {
        for (int j = 1; j <= size_second; j++) {
            if (first[i] == second[j]) {
                memo[i][j] = 1 + memo[i - 1][j - 1];
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j-1]);
            }
        }
    }
    int* sol = new int[MAX_SIZE];
    int size = 0; 
    for (int i = size_first, j = size_second; j > 0 ;) {
        if (first[i] == second[j]) {
            sol[++size] = first[i];
            j--; i--;
        } else if (memo[i - 1][j] > memo[j][i -1]) {
            i--;
        } else {
            j--;
        }
    }
    out << size << endl;
    for (int i = size; i > 0; i--) {
        out << sol[i] << " ";
    }
    return 0;
}
