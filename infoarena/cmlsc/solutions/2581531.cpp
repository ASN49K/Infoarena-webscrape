#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, maxx;
int a[1026], b[1026], sol[1026][1026];
stack<int> vec;

int main() {
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                sol[i][j] = sol[i - 1][j - 1] + 1;
            else
                sol[i][j] = max(sol[i - 1][j], sol[i][j - 1]);

    int i = n, j = m;
    while(true) {
        if (i == 1 && j == 1) {
            if (sol[i][j])
                vec.push(a[i]);
            break;
        }

        if (sol[i - 1][j - 1] == sol[i][j] && i > 1 && j > 1)
            i--, j--;
        else if (sol[i - 1][j] == sol[i][j] && i > 1)
            i--;
        else if (sol[i][j - 1] == sol[i][j] && j > 1)
            j--;
        else {
            vec.push(a[i]);
            i = max(1, i - 1);
            j = max(1, j - 1);
        }
    }

    fout << sol[n][m] << '\n';
    while (!vec.empty())
        fout << vec.top() << ' ', vec.pop();
    return 0;
}
