#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
vector<int> v, w;

int d[20000][20000];

void cmlsc () {

    for(int i = 1; i <= v.size(); ++i) {
        for(int j = 1; j <= w.size(); ++j) {
            if(!i || !j) d[i][j] = 0;
            else if(v[i - 1] == w[j - 1]) d[i][j] = 1 + d[i - 1][j - 1];
            else d[i][j] = max( d[i - 1][j], d[i][j - 1] );
        }
    }

    int dmax = 0;
    for(int i = 0; i <= v.size(); ++i) {
        for(int j = 0; j <= w.size(); ++j){
            if(d[i][j] > dmax) dmax = d[i][j];
        }
    }

    out << dmax << endl;

    int currentD = 1;
    while(currentD < dmax + 1) {
        for(int i = 1; i <= v.size(); ++i) {
            for(int j = 1; j <= w.size(); ++j){
                if(d[i][j] == currentD) {
                    out << v[i - 1] << " ";
                    currentD++;
                }
            }
        }
    }
}

int main()
{
    in >> n >> m;
    v.resize(n);
    w.resize(m);

    for(int i = 0; i < n; ++i) {
        in >> v[i];
    }
    for(int i = 0; i < m; ++i) {
        in >> w[i];
    }

    cmlsc();

    return 0;
}

