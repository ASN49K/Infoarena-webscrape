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

void printString(vector<int> v, vector<int> w, vector< vector<int> > parents, int i, int j) {
    switch(parents[i][j]) {
        case 1:
            if(i - 1 >= 0 && j - 1 >= 0) printString(v, w, parents, i - 1, j - 1);
            break;
        case 2:
            if(j - 1 >= 0) printString(v, w, parents, i, j - 1);
            break;
        case 3:
            if(i - 1 >= 0) printString(v, w, parents, i - 1, j);
            break;
    }
    if(v[i] == w[j]) out << v[i] << " ";
}

void cmlsc (vector<int> v, vector<int> w) {
    int n = v.size();
    int m = w.size();
    vector< vector<int> > d(n);
    vector< vector<int> > parents(n);
    for(int i = 0; i < n; ++i) parents[i].resize(m);
    for(int i = 0; i < n; ++i) d[i].resize(m, 0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            if(!i || !j){
                if(v[i] == w[j]) d[i][j] = 1;
                else d[i][j] = 0;
            }else if(v[i] == w[j]) {
                d[i][j] = 1 + d[i - 1][j - 1];
                parents[i][j] = 1;
            }else if(d[i][j - 1] > d[i - 1][j]){
                d[i][j] = (j > 0)?d[i][j - 1]:0;
                parents[i][j] = 2;
            }else {
                d[i][j] = (i > 0)?d[i - 1][j]:0;
                parents[i][j] = 3;
            }
        }
    }
    out << d[n - 1][m - 1] << "\n";

    printString(v, w, parents, n - 1, m - 1);

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

