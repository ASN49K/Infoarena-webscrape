#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[1025], y[1025], v[2][1025], n, m, i, j;
char dir[1025][1025];
stack<int> stiva;

void drum(int a, int b) {
    if(dir[a][b] == 'H') {
        stiva.push(x[a]);
        if(a > 1 && b > 1) {
            drum(a-1, b-1);
        }
    }
    if(dir[a][b] == 'N' && a > 1) {
        drum(a-1, b);
    }
    if(dir[a][b] == 'W' && b > 1) {
        drum(a, b-1);
    }
}

int main() {
    fin >> n >> m;
    for(i = 1; i <= n; i++) {
        fin >> x[i];
    }
    for(i = 1; i <= m; i++) {
        fin >> y[i];
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(x[i] == y[j]) {
                v[i%2][j] = v[(i+1)%2][j - 1] + 1;
                dir[i][j] = 'H';
            }
            else {
                if(v[i%2][j-1] > v[(i+1)%2][j]) {
                    v[i%2][j] = v[i%2][j-1];
                    dir[i][j] = 'W';
                }
                else {
                    v[i%2][j] = v[(i+1)%2][j];
                    dir[i][j] = 'N';
                }
            }
        }
    }
    drum(n, m);
    fout << v[n%2][m] << '\n';
    while(!stiva.empty()) {
        fout << stiva.top() << ' ';
        stiva.pop();
    }
    fin.close();
    fout.close();
    return 0;
}
