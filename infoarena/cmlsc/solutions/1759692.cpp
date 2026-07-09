#include<bits/stdc++.h>
using namespace std;
#define in f
#define out g

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n;
int m;
int v1[1025];
int v2[1025];
int solution[1025];
int M[1025][1025];
int h ;

int main() {

    in >> n;
    in >> m;
    for(int i = 1; i <= n; ++i) {
        in >> v1[i];
    }
    for(int i = 1; i <= m; ++i) {
        in >> v2[i];
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(v1[i] == v2[j]) {
                M[i][j] = M[i][j - 1] + 1;
            } else {
                M[i][j] = max(M[i][j - 1], M[i - 1][j]);
            }
        }
    }
    out << M[n][m] << endl;
    for(int i = n; i >= 1; --i) {
        for(int j = m; j >= 1; --j) {
            if(v1[i] == v2[j] && ) {
                solution[h] = v1[i];
                h++;
            }
        }
    }
    for(int i = h - 1; i >= 0; --i) {
        out << solution[i] << " ";
    }
}
