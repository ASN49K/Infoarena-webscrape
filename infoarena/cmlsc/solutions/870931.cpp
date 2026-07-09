#include <fstream>
#include <queue>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025];
int na,nb,i,j;
queue <int> q;

int main() {
    f >> na >> nb;
    for (i=1;i<=na;i++) f >> a[i][0];
    for (i=1;i<=nb;i++) f >> a[0][i];
    int mj = 1;
    for (i=1;i<=na;i++) for (j=mj+1;j<=nb;j++) {
        if (a[i][0] == a[0][j] && a[i][0] != -1 && a[0][j] != 0) {
            q.push(a[i][0]);
            mj = j;
            a[i][0] = a[0][j] = -1;
        }
    }
    g << q.size() << '\n';
    while (!q.empty()) {
        g << q.front() << ' ';
        q.pop();
    }
}
