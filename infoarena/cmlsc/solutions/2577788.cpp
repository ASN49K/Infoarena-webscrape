#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAX = 1025;
int n, m, a[MAX], b[MAX], d[MAX][MAX];
vector <int> sir;

void read() {
    for(int i = 1; i <= n; i++)
        in >> a[i];

    for(int i = 1; i <= m; i++)
        in >> b[i];
}

void solve() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else 
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
}

int main() {
    in >> n >> m;
    read();
    solve();

    out << d[n][m] << "\n";

    while(n > 0 && m > 0) {
        if(a[n] == b[m]) {
            sir.push_back(a[n]);
            n--;
            m--;
        } else if(n > m)
            n--;
        else 
            m--;
    }

    for(unsigned int i = 0; i < sir.size(); i++)
        out << sir[i] << " ";

    return 0;
}