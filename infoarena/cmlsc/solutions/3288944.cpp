#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = (1 << 10) + 7;

int a[N], b[N];
int dp[N][N]; /// dp[i][j] = lcs pentru a[1..i] si b[1..j]

int main() {
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) /// in cazul in care ultimele elm sunt egale, nu exista nimic mai bine decat sa le imperechem asa cum sunt
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else /// in schimb, daca nu sunt egale, unul dintre ele trebuie sa ramana desperecheat (i -= 1 sau j -= 1)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector < int > ans;
    int i(n), j(m);
    while (i != 0 && j != 0) {
        if (a[i] == b[j]) { /// pentru a reconstrui subsirul de lungime maxima, trebuie sa urmam aceeasi pasi pe care i-am urmat la aflarea lungimii sale
            ans.push_back(a[i]); /// elementele care se imperecheaza vor fi astfel acelea la care dp-ul creste in valoare (a[i] == b[j])
            i--, j--;
        }
        else {
            if (dp[i - 1][j] < dp[i][j - 1]) /// in rest, vom urma aceeasi decizie pe care am urmat-o in primul for
                j--;
            else
                i--;
        }
    }
    reverse(ans.begin(), ans.end()); /// raspunsul va fi reconstruit de la coada la cap, asa ca trebuie inversat pentru afisare
    fout << ans.size() << '\n';
    for (int i : ans)
        fout << i << ' ';
}