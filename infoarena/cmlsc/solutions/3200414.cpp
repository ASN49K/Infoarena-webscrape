#include <iostream>
#include <fstream>
#include <stdio.h>

int32_t max(int32_t val1, int32_t val2) {
    return (val1 > val2) ? val1 : val2;
}

const int32_t MAX_M = 1024;
const int32_t MAX_N = 1024;

int32_t vec1[MAX_M], vec2[MAX_N];
int32_t dp[MAX_M][MAX_N];
int32_t sir[MAX_N];
int main() {
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    int32_t m, n;
    fin >> m >> n;
    for(int32_t i = 0; i != m; ++i)
        fin >> vec1[i];
    for(int32_t i = 0; i != n; ++i)
        fin >> vec2[i];
    
    for(int32_t i = 0; i != n; ++i)
        dp[0][i] = vec1[0] == vec2[i];
    for(int32_t i = 1; i != m; ++i)
        dp[i][0] = vec1[i] == vec2[0];
    for(int32_t i = 1; i != m; ++i)
        for(int32_t j = 1; j != n; ++j)
            if(vec1[i] == vec2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
    int32_t row = m - 1, col = n - 1, top = 0;
    while(row != -1 && col != -1 && dp[row][col]) {
        if(vec1[row] == vec2[col]) {
            sir[top++] = vec1[row];
            --row;
            --col;
        } else if(!row) {
            --col;
        } else if(!col) {
            --row;
        } else if(dp[row - 1][col] > dp[row][col - 1]) {
            --row;
        } else {
            --col;
        }
    }
    fout << dp[m - 1][n - 1] << '\n';
    for(int32_t i = top - 1; i != -1; --i)
        fout << sir[i] << ' ';

    fin.close();
    fout.close();

    return 0;
}