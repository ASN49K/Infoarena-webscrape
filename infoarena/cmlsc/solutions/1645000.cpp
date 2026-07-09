#include <fstream>
#include <stack>

using namespace std;

short a[1100], b[1100];
short c[1100][1100];
stack<short> s;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m;
    f >> n >> m;
    for(int i = 1; i <= n; i ++) f >> a[i];
    for(int i = 1; i <= m; i ++) f >> b[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) c[i][j] = c[i - 1][j - 1] + 1;
            c[i][j] = max(c[i][j], c[i - 1][j]);
            c[i][j] = max(c[i][j], c[i][j - 1]);
        }
    }
    g << c[n][m] << "\n";
    while(c[n][m] != 0) {
        if(c[n][m] == c[n - 1][m]) n --;
        else if(c[n][m] == c[n][m - 1]) m --;
        else if(c[n][m] > c[n][m - 1] && c[n][m] > c[n - 1][m]) {
            s.push(a[n]),
            n --;
            m --;
        }
    }
    while(!s.empty()) {
        g << s.top() << " ";
        s.pop();
    }
    g << "\n";
    return 0;
}
