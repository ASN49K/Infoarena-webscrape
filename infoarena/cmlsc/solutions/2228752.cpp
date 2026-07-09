#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define cin in
#define cout out

using namespace std;

int lcs[1025][1025];

int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int m, n;
    int i, j;


    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> b(m + 1);
    vector<int> sol;
    lcs[0][0] = 0;

    for (i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for (j = 1; j <= m; ++j){
        cin >> b[j];
    }

    for (i = 1; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            if (a[i] == b[j])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    i = n;
    j = m;
    while (i > 0 && j > 0){
        if (lcs[i][j] == lcs[i - 1][j]){
            i = i - 1;
        }
        else{
            if (lcs[i][j] == lcs[i][j - 1]){
                j = j - 1;
            }
            else{
                sol.push_back(a[i]);
                i = i - 1;
                j = j - 1;
            }
        }

    }

    cout << lcs[n][m] << '\n';
    for (auto it = sol.rbegin(); it != sol.rend(); ++it)
        cout << *it << ' ';
}
