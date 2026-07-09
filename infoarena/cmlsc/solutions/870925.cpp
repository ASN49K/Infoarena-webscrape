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
    for (i=1;i<=na;i++) f >> a[0][i];
    for (i=1;i<=nb;i++) f >> a[i][0];
    for (i=1;i<=nb;i++) for (j=1;j<=na;j++) {
        if (a[i][0] == a[0][j]) {
            q.push(a[i][0]);
            continue;
        }
    }
    g << q.size() << '\n';
    while (!q.empty()) {
        g << q.front() << ' ';
        q.pop();
    }
}
