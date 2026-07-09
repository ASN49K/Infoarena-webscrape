#include <bits/stdc++.h>
using namespace std;
int v1[1025], v2[1025], lung[1025][1025];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
void refac_subsirul(int i, int j) {
    if (lung[i][j] == 0)
        return;
    if (v1[i] == v2[j]) {
        refac_subsirul(i - 1, j - 1);
        out << v1[i] << " ";
    } else {
        if (lung[i - 1][j] > lung[i][j - 1])
            i--;
        else
            j--;
        refac_subsirul(i, j);
    }
}
int main() {
    int n, m, i, j;
    in >> n >> m;
    for(i = 1;i <= n;i++)
        in >> v1[i];
    for(i = 1;i <= m;i++)
        in >> v2[i];
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++) {
            if (v1[i] == v2[j]) {
                lung[i][j] = 1 + lung[i - 1][j - 1];
            } else {
                lung[i][j] = max(lung[i][j - 1], lung[i - 1][j]);
            }
        }
    }
    out << lung[n][m] << "\n";
    refac_subsirul(n, m);
    return 0;
}
