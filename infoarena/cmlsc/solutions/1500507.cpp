#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>

#define pb push_back

using namespace std;

int a[1100], b[1100];
int sol[1100][1100];

int main() {
    ifstream cin("cmlsc.in");
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i] == b[j])
                sol[i][j] = (i > 0 && j > 0)? sol[i - 1][j - 1] + 1 : 1;
            else sol[i][j] = max(sol[i - 1][j], sol[i][j - 1]);

    vector <int> vctSol;
    for (int i = n - 1, j = m - 1; i && j; ) {
        if (a[i] == b[j]) {
            vctSol.pb(a[i]);
            i--;
            j--;
        }
        else if (sol[i - 1][j] > sol[i][j - 1])
            i--;
        else j--;
    }

    printf("%d\n", vctSol.size());
    for (int i = vctSol.size() - 1; i >= 0; i--)
        printf("%d ", vctSol[i]);

    return 0;
}

