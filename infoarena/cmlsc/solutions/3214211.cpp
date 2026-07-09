#include <bits/stdc++.h>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");

int v3[2050][2050];
int subsir[1024];

void cmlsc(int v1[], int m, int v2[], int n) {

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
    int i = m, j = n;
    int k = 0;
    while(i > 0) {
        if(v1[i] == v2[j]) {
            subsir[++k] = v1[i];
            --i;
            --j;
        }
        else if(v3[i-1][j] < v3[i][j-1]) {
            --j;
        }
        else
            --i;
    }
    for(i = k; i; i--) {
        fo << subsir[i] << " ";
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
    cmlsc(arr1, m, arr2, n);
}