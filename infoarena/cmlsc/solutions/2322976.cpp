#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

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
    vector< vector<int> > d(n);
    vector< vector<tile> > parents(n);
    for(int i = 0; i < n; ++i) parents[i].resize(m);
    for(int i = 0; i < n; ++i) d[i].resize(m, 0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            if(!i || !j){
                if(v[i] == w[j]) d[i][j] = 1;
                else d[i][j] = 0;
            }else if(v[i] == w[j]) {
                d[i][j] = 1 + d[i - 1][j - 1];
                parents[i][j] = tile(i - 1, j - 1);
            }else if(d[i][j - 1] > d[i - 1][j]){
                d[i][j] = (j > 0)?d[i][j - 1]:0;
                parents[i][j] = tile(i, j - 1);
            }else {
                d[i][j] = (i > 0)?d[i - 1][j]:0;
                parents[i][j] = tile(i - 1, j);
            }
        }
    }
    out << d[n - 1][m - 1] << "\n";

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

