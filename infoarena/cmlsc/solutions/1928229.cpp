#include <fstream>
#include <algorithm>
using namespace std;
const int MAX_VAL = 1025;
int lcs(int x1[MAX_VAL], int x2[MAX_VAL], int n, int m, int insc[MAX_VAL][MAX_VAL]) {
    int cnt[MAX_VAL][MAX_VAL];
    for (int i = 0; i <= n; i++) cnt[i][0] = 0;
    for (int i = 1; i <= m; i++) cnt[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (x1[i] == x2[j]) {
                cnt[i][j] = cnt[i-1][j-1] + 1;
                insc[i][j] = 2;
            }
            else {
                cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
                insc[i][j] = (cnt[i-1][j] >= cnt[i][j-1]) ? 3 : 1;
            }
    return cnt[n][m];
}
int main() {
    ifstream fi("cmlsc.in");
    ofstream fo("cmlsc.out");
    int n, m;
    fi >> n >> m;
    int x1[MAX_VAL], x2[MAX_VAL];
    for (int i = 1; i <= n; i++) fi >> x1[i];
    for (int j = 1; j <= m; j++) fi >> x2[j];
    int insc[MAX_VAL][MAX_VAL];
    int aux_l = lcs(x1, x2, n, m, insc);
    fo << aux_l << '\n';
    int mem_i = n, mem_j = m;
    int final_res[MAX_VAL];
    int length = aux_l;
    while (aux_l) {
        if (insc[mem_i][mem_j] == 1) mem_j--;
        else
        if (insc[mem_i][mem_j] == 3) mem_i--;
        else {
            final_res[aux_l--] = x1[mem_i];
            mem_i--;
            mem_j--;
        }
    }
    for (int i = 1; i <= length; i++) fo << final_res[i] << ' ';
    return 0;
}
