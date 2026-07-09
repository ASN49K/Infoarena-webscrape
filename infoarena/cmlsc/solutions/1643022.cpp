#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define NMax 1025

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
vector<int> A;
vector<int> B;
int C[NMax][NMax];
vector<int> sol;

void dodp() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (A[i] == B[j]) {
                C[i][j] = 1+C[i-1][j-1];
            } else {
                C[i][j] = max(C[i][j-1], C[i-1][j]);
            }
        }
    }

    g<<C[n][m]<<'\n';

    int i=n;
    int j=m;

    while (i > 1 || j > 1) {
        if (A[i] == B[j]) {
            sol.pb(A[i]);
            i--; j--;
        } else {
            if (C[i][j] == C[i-1][j])
                i--;
            else
                j--;
        }
    }

    for (int p=sol.size()-1;p>=1;p--) {
        g<<sol[p]<<' ';
    }
    if (sol.size() > 0)
        g<<sol[0];
    g<<endl;
}

void read() {
    f>>n>>m;
    A.pb(0); B.pb(0);
    for (int i=1;i<=n;i++) {
        int x; f>>x;
        A.pb(x);
    }

    for (int i=1;i<=m;i++) {
        int x; f>>x;
        B.pb(x);
    }
}

int main() {

    read();
    dodp();

    f.close(); g.close();
    return 0;
}
