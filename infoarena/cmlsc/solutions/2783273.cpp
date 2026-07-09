#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int len[NMAX][NMAX], N, M;
int a[NMAX], b[NMAX];
void read() {
    fin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        fin >> a[i];
    }
    for (int i = 1; i <= M; ++i) {
        fin >> b[i];
    }
}
void calculateLength() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (a[i] == b[j]) {
                len[i][j] = len[i - 1][j - 1] + 1;
            }
            else {
                len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            }
        }
    }
}
vector<short> getLCS(int i, int j) {
    vector<short> lcs;
    if(i == 0 || j == 0) {
        return lcs;
    }
    if (a[i] == b[j]) {
        lcs = getLCS(i - 1, j - 1);
        lcs.push_back(a[i]);
    }
    else if (len[i][j - 1] > len[i - 1][j]) {
        lcs = getLCS(i, j - 1);
    }
    else {
        lcs = getLCS(i - 1, j);
    }
    return lcs;
}
int main()
{
    read();
    calculateLength();
    fout << len[N][M] << "\n";
    vector<short> v = getLCS(N, M);
    for (int i = 0; i < v.size(); ++i) {
        fout << v[i] << " ";
    }
    return 0;
}
