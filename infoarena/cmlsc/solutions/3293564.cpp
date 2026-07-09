#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");

int main(){
    int n, m;
    fin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i = 1; i<=n; i++) fin >> a[i];
    for(int i = 1; i<=m; i++) fin >> b[i];

    vector<vector<int>> grid(n+1, vector<int>(m+1, 0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i] == b[j]){
                grid[i][j]= 1 + grid[i-1][j-1];
            } else {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }
    vector<int> sir;
    for(int i = n, j = m; i;){
        if(a[i] == b[j]){
            sir.push_back(a[i]); --i; --j;
        } else if(grid[i-1][j] < grid[i][j-1]){
            --j;
        } else --i;
    }

    reverse(sir.begin(), sir.end());
    fout << sir.size() << endl;
    for(auto d : sir){
        fout << d << " ";
    }
}
