/*

d[i][j] - subsirul de lungime maxima din primele
i elemente a lui A, care apartin primelor j
elemente a lui B

*/

#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;

#define VMAX 1027

short n, m;
short a[VMAX], b[VMAX];
short d[VMAX][VMAX];
vector<short> ans;

void solve(){

    // citirea datelor de intrare
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }

    // programarea dinamica in sine
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){

            if(a[i] == b[j]){

                d[i][j] = d[i - 1][j - 1] + 1;

            }
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }

        }
    }

    // afisarea lungimii maxime a unui subsir
    cout << d[n][m] << '\n';

    // traceback-ul algoritmului pentru determinarea solutiilor
    int x = n, y = m;

    while(x > 0 && y > 0){

        if(a[x] == b[y]){

            ans.push_back(a[x]);
            --x, --y;

        }
        else{

            if(d[x - 1][y] > d[x][y - 1]){
                --x;
            }
            else{
                --y;
            }

        }

    }

    // inversarea vectorului de solutii pentru ca 
    // datele au fost memorate in sens invers
    reverse(ans.begin(), ans.end());

    // afisarea vectorului solutie
    for(short nr : ans){
        cout << nr << " ";
    }
    cout << '\n';

}

int main(){
    
    ios_base::sync_with_stdio(false);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}