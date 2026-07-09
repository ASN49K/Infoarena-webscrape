#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// ifstream cin("input");ofstream cout("output");
ifstream cin("cmlsc.in");ofstream cout("cmlsc.out");

vector<int> a, b;
vector<vector<int>> dp; // dp[i][j] = lungimea maxima a unui subsir comun pana la poz i in A si poz j in B

void afisare(int i, int j) {

    // eu sunt la dp[i][j] -> de unde am venit?
    // daca dp[i][j] == dp[i-1][j-1] + 1 si A[i] == B[j] -> A[i] face parte din solutie si eu vin din dp[i-1][j-1]
    // daca dp[i][j] == dp[i-1][j] -> vin din acest dp
    // daca dp[i][j] == dp[i][j-1] -> vin din acest dp

    if (i < 1 || j < 1) { // stare de start -> ma opresc
        return;
    }
    if (dp[i][j] == dp[i-1][j-1] + 1 && a[i] == b[j]) {
        afisare(i - 1, j - 1);
        cout << a[i] << " "; // afisez atunci cand ma intorc
        return;
    }
    if (dp[i][j] == dp[i-1][j]) { // ignor pozitia i
        afisare(i - 1, j);
        return;
    }
    if (dp[i][j] == dp[i][j-1]) { // ignor pozitia j
        afisare(i, j - 1);
        return;
    }
}

int main(){

    int n, m;
    cin>>n>>m;

    a.resize(n+1);
    b.resize(m+1);
    dp.resize(n+1, vector<int>(n+1, 0));

    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=1; i<=m; i++){
        cin>>b[i];
    }

    // starea initiala dp[i][0] = 0 si dp[0][j] = 0 (nu trebuie sa le mai dam valori pentru ca tot dp-ul este 0 din start)

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // recurenta in spate
            dp[i][j] = max(dp[i-1][j-1] + (a[i] == b[j]) , max(dp[i-1][j] , dp[i][j-1]));
        }
    }

    /*
    EXEMPLE:
    dp[1][1] = 0
    A = 1
    B = 7

    dp[1][3] = 0
    A = 1
    B = 7 5 8

    dp[2][3] = 1
    A = 1 7
    B = 7 5 8

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    */

    // starea finala dp[n][m]
    cout<<dp[n][m]<<'\n';

    // afisare
    afisare(n, m);

}