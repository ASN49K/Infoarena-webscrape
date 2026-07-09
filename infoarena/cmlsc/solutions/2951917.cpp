#include <bits/stdc++.h>
using namespace std;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int X[1024], Y[1024];
int L[1024][1024], S[1024];

void generare() {
    int i = m, j = n, k = L[m][n];
    while(k) {
        if (X[i] == Y[j]) {
            S[k] = X[i];
            i--;
            j--;
            k--;
        }
        else
            if (L[i-1][j] >= L[i][j-1])
                i--;
            else
                j--;
    }
}

int main()
{
    f >> m >> n;
    for (int i = 1; i <= m; i++) {
        f >> X[i];
    }
   for (int i = 1; i <= n; i++) {
        f >> Y[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    g << L[m][n] << '\n';
    generare();
    for (int i = 1; i <= L[m][n]; i++) {
        g << S[i] << ' ';
    }
    f.close();
    g.close();
    return 0;
}

