#include <fstream>
#include <algorithm>
#include <vector>
#define Nmax 1030

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,d[Nmax][Nmax];
int v[Nmax],w[Nmax];
vector <int> sol;

void ReadInput() {

    f>>n>>m;
    for (int i=1; i<=n; ++i) f>>v[i];
    for (int i=1; i<=m; ++i) f>>w[i];
}

void Rebuild(int &i, int &j) {

    while (i!=0 && j!=0) {

        if (v[i]==w[j]) {

            sol.push_back(v[i]);
            --i;
            --j;
        }
        else if (d[i-1][j]>d[i][j-1]) --i;
        else --j;
    }
}

void Solve() {

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) {

            if (v[i]==w[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }



    g<<d[n][m]<<'\n';

    Rebuild(n,m);

    sort(sol.begin(),sol.end());

    for (auto x: sol) g<<x<<' ';
    g<<'\n';
}

int main() {

    ReadInput();
    Solve();

    f.close(); g.close();
    return 0;
}
