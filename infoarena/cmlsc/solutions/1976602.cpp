/*
    Keep It Simple!
*/

#include <fstream>
#include <stack>

using namespace std;

const int MAX_N = 1025;

int m, n;
int a[MAX_N], b[MAX_N];
int mat[MAX_N][MAX_N];

void ReadInput() {
    ifstream f("cmlsc.in");

    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    for (int i = 1; i <= m; ++i)
        f >> b[i];
}

int lcs() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    return mat[n][m];
}

void Reconstruct(ofstream& g) {
    int i = n;
    int j = m;
    stack<int> st;
    while (i != 0 && j != 0) {
        if (a[i] == b[j]) {
            st.push(a[i]);
            --i,--j;
        } else {
            mat[i-1][j] > mat[i][j-1] ? --i:--j;
        }
    }

    while(st.size()!=0) {
        g << st.top() << " ";
        st.pop();
    }
}

void Solve() {
    ReadInput();

    ofstream g("cmlsc.out");
    g << lcs() << '\n';
    Reconstruct(g);
    g << '\n';
    g.close();
}

int main() {
    Solve();
    return 0;
}
