#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    unsigned int M, N, i, j;
    fin >> M >> N;
    vector<unsigned int> a(M+1), b(N+1);
    vector<vector<unsigned int>> d(M+1, vector<unsigned int>(N+1));
    for(i=1; i<=M; ++i) {
        fin >> a[i];
        d[i][0] = 0;
    }
    for(j=1; j<=N; ++j) {
        fin >> b[j];
        d[0][j] = 0;
    }

    for(i=1; i<=M; ++i) {
        for(j=1; j<=N; ++j) {
            if(a[i] == b[j]) {
                d[i][j] = d[i-1][j-1] + 1;
            } else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    stack<unsigned int> sir;
    i = M, j = N;
    while(i && j) {
        if(a[i] == b[j]) {
            sir.push(a[i]);
            --i, --j;
        } else if(d[i-1][j] > d[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    fout << d[M][N] << endl;
    for(i=0; i<d[M][N]; ++i) {
        fout << sir.top() << ' ';
        sir.pop();
    }
    fout << endl;
}
