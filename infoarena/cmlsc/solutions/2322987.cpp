#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int d[10000][10000];

struct tile{
    int i, j;

    tile(int _i = -1, int _j = -1) {
        i = _i;
        j = _j;
    }
};

void printString(vector<int> v, vector<int> w, vector< vector<tile> > parents, tile t) {
    if(parents[t.i][t.j].i != -1 && parents[t.i][t.j].j != -1)
        printString(v, w, parents, tile(parents[t.i][t.j].i, parents[t.i][t.j].j));
    if(v[t.i] == w[t.j]) out << v[t.i] << " ";
}

void cmlsc (vector<int> v, vector<int> w) {
    int n = v.size();
    int m = w.size();
    vector< vector<tile> > parents(n);
    for(int i = 0; i < n; ++i) parents[i].resize(m);

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j) {
            if(!i || !j){
                d[i][j] = 0;
            }else if(v[i - 1] == w[j - 1]) {
                d[i][j] = 1 + d[i - 1][j - 1];
                parents[i - 1][j - 1] = tile(i - 2, j - 2);
            }else if(d[i][j - 1] > d[i - 1][j]){
                d[i][j] = d[i][j - 1];
                parents[i - 1][j - 1] = tile(i - 1, j - 2);
            }else {
                d[i][j] = d[i - 1][j];
                parents[i - 1][j - 1] = tile(i - 2, j - 1);
            }
        }
    }
    out << d[n][m] << "\n";

    printString(v, w, parents, tile(n - 1, m - 1));

}

int main()
{
    int n, m;
    in >> n >> m;
    vector<int> v(n), w(m);
    for(int i = 0; i < n; ++i) in >> v[i];
    for(int i = 0; i < m; ++i) in >> w[i];

    cmlsc(v, w);

    return 0;
}

