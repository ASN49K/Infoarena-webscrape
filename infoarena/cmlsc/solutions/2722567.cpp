#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, ind;
vector <int> a, b, best;
vector <vector <int> > d;

void init() {
    a = vector <int> (n + 1);
    b = vector <int> (m + 1);
    d = vector <vector <int> > (n + 1, vector <int> (m + 1));
    best = vector <int> (max(n, m) + 1);
}

void read() {
    f >> n >> m;
    init();
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= m; ++i)
        f >> b[i];
}

void solve() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    for(int i = n, j = m; i;) {
        if(a[i] == b[j])
            best[++ind] = a[i--], j--;
        else {
            if(d[i - 1][j] < d[i][j - 1])
                j --;
            else i --;
        }
    }

}

void print() {
    g << ind << '\n';
    for(int i = ind; i; i--)
        g << best[i] << " ";
}

int main()
{
    read();
    solve();
    print();
}
