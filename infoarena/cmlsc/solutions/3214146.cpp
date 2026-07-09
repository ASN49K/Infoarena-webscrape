#include <bits/stdc++.h>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int v3[2050][2050];

void cmlsc(int v1[], int m, int v2[], int n) {
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            v3[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(v1[i] == v2[j]) {
                v3[i][j] = v3[i-1][j-1] + 1;
            }
            else {
                v3[i][j] = max(v3[i-1][j],v3[i][j-1]);
            }
        }
    }
    fo << v3[m][n] << "\n";
    int k = 0;
    for(int i = 1; i <= m; i++) {
        if(v3[i][n] != k) {
            fo << v1[i] << " ";
            k++;
        }
    }
}

int main() {
    int m, n;
    fi >> m >> n;
    int arr1[1025];
    int arr2[1025];
    for(int i = 1; i <= m; i++) {
        fi >> arr1[i];
    }
    for(int i = 1; i <= n; i++) {
        fi >> arr2[i];
    }
    if(m > n) {
        cmlsc(arr1, m, arr2, n);
    }
    else
        cmlsc(arr2, n, arr1, m);
}