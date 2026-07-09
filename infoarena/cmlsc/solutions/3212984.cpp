#include <bits/stdc++.h>
#define DIM 1100
#define y1 eiuhrf

using namespace std;

ifstream fin("cmlsc.in");

ofstream fout("cmlsc.out");

int dp[DIM][DIM];

int a[DIM], b[DIM];

vector <int> v;

int m, n, i, j;

void path(int i, int j){

    while(i && j){

        if(a[i] == b[j]){

            v.push_back(a[i]);

            i--;

            j--;

        }

        else if(dp[i][j - 1] >= dp[i - 1][j])

            --j;

        else --i;

    }

}

int main(){

    fin >> n >> m;

    for(i=1;i<=n;i++)

        fin >> a[i];

    for(j=1;j<=m;j++)

        fin >> b[j];

    for(i=1;i<=n;i++)

        for(j=1;j<=m;j++)

            if(a[i] == b[j])

                dp[i][j] = dp[i - 1][j - 1] + 1;

            else dp[i][j] = max(dp[i - 1][j], dp[j][i - 1]);

    fout << dp[n][m] << "\n";

    path(n, m);

    reverse(v.begin(), v.end());

    for(auto k : v)

        fout << k << " ";


}
