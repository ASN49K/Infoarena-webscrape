#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025];
int com[1025][1025];

int main() {
    int n,m;
    fin>>n>>m;
    for (int i=1;i<=n;i++) {
        fin>>a[i];
    }
    for (int i=1;i<=m;i++) {
        fin>>b[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                com[i][j]=max(1+com[i-1][j-1], max(com[i][j-1],com[i-1][j]));
            }else {
                com[i][j]=max(com[i][j-1],com[i-1][j]);
            }
        }
    }
    fout<<com[n][m]<<"\n";

    vector<int> ans;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (a[i] == b[j] && com[i - 1][j - 1] + 1 == com[i][j]) {
            ans.push_back(a[i]);
            i--;
            j--;
        } else if (com[i][j] == com[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        fout << i << " ";
    }
    return 0;
}