#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    int n, m;
    int v1[1024], v2[1024];
    int ult[1024][1024] = {-1}; 
    int l[1024][1024] = {0};
    fin >> n >> m;
    for(int i = 0; i < n; i++)
        fin >> v1[i];
    for(int j = 0; j < m; j++)
        fin >> vj[j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(v1[i] != v2[j]) {
                if(l[i][j - 1] > l[i - 1][j]) {
                    ult[i][j] = ult[i][j - 1];
                    l[i][j] = l[i][j - 1];
                } else {
                    ult[i][j] = ult[i - 1][j];
                    l[i][j] = l[i - 1][j];
                }
            } else {
                ult[i][j] = j;
                l[i][j] = l[i - 1][j - 1] + 1;
            }
        }
    fout << l[n][m] << endl << 0;
}