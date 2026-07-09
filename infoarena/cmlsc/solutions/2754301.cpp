#include <bits/stdc++.h>
#define NMAX 1025
using namespace std;
typedef long long ll;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

const string file = "cmlsc";

ifstream fin(file + ".in");
ofstream fout(file + ".out");

int n, m;
int a[NMAX], b[NMAX];
int pd[NMAX][NMAX];

vector<int>sol;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                pd[i][j] = pd[i - 1][j - 1] + 1;
            else
                pd[i][j] = max(pd[i - 1][j], pd[i][j - 1]);
        }
    }
    int i = n, j = m;
    while (i && j){
        if(a[i] == b[j])
            sol.push_back(a[i]), i--, j--;
        else if(pd[i - 1][j] > pd[i][j - 1])
            i--;
        else
            j--;
    }
    fout << sol.size() << "\n";
    for(int i = sol.size() - 1; i >= 0; i--)
        fout << sol[i] << " ";
    return 0;
}
