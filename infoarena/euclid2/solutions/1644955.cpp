#include <fstream>
#include <vector>

using namespace std;

int mn = 25, n;
long long ret;
vector<int> M[20];
int p[20];
int mx[20];

void bkt(int v) {
    bool c[20];
    for(int i = 1; i <= n; i ++) c[i] = false;
    for(int i = 0; i < M[v].size(); i ++) c[ p[M[v][i]] ] = true;
    for(int j = 1; j <= mn; j ++)
        if(!c[j]) {
            p[v] = j;
            mx[v] = max(mx[v - 1], j);
            if(v == n) {
                if(mx[v] < mn) mn = mx[v], ret = 1;
                else if(mx[v] == mn) ret ++;
            }
            else bkt(v + 1);
        }
    p[v] = 0;
}

int main()
{
    ifstream f("colorare.in");
    ofstream g("colorare.out");
    int m, x, y;
    f >> n >> m;
    for(int i = 1; i <= m; i ++) {
        f >> x >> y;
        M[x].push_back(y);
        M[y].push_back(x);
    }

    bkt(1);
    g << mn << " " << ret << "\n";
    return 0;
}
