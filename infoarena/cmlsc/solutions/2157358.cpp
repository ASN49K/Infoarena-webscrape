
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>

#define max(a, b) ((a) > (b)) ? (a) : (b)

using namespace std;

const char *IN = "cmlsc.in";
const char *OUT = "cmlsc.out";
const int MAXLEN = 1024;

int d[MAXLEN + 1][MAXLEN + 1];
pair<int, int> backlinks[MAXLEN + 1][MAXLEN + 1];


int main() {
    ios::sync_with_stdio(false);
    ifstream fin(IN);
    ofstream fout(OUT);

    int N, M;
    int v[MAXLEN], w[MAXLEN];

    fin >> N >> M;
    for (int i = 0; i < N; ++i)
        fin >> v[i];
    for (int i = 0; i < M; ++i)
        fin >> w[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int x = i + 1, y = j + 1;
            if (v[i] == w[j]) {
                d[x][y] = d[x - 1][y - 1] + 1;
                backlinks[x][y] = make_pair(x - 1, y - 1);
            } else {
                if (d[x - 1][y] > d[x][y - 1]) {
                    d[x][y] = d[x - 1][y];
                    backlinks[x][y] = make_pair(x - 1, y);
                } else {
                    d[x][y] = d[x][y - 1];
                    backlinks[x][y] = make_pair(x, y - 1);
                }
            }
        }
    }

    stack<int> maxseq;
    int x = N, y = M;
    while (x != 0 && y != 0) {
        if (v[x - 1] == w[y - 1])
            maxseq.push(v[x - 1]);
        int newx = backlinks[x][y].first;
        int newy = backlinks[x][y].second;

        x = newx, y = newy;
    }

    fout << maxseq.size() << endl;
    while (maxseq.size() != 0) {
        fout << maxseq.top() << ' ';
        maxseq.pop();
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
