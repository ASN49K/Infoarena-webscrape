#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025], b[1025], lcs[1026][1026];
int cnt, ans[1025];
void back(int i, int j){
    if(i == 0 || j == 0) return;
    if(a[i] == b[j]) {ans[++cnt] = a[i]; back(i-1, j-1);}
    else{
        if(lcs[i-1][j] > lcs[i][j-1]){
            back(i-1, j);
        }
        else back(i, j-1);
    }
}
int main(){
    fin >> n >> m;
    for(int i = 1; i<=n; i++) fin >> a[i];
    for(int i = 1; i<=m; i++) fin >> b[i];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i] == b[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    back(n,m);
    fout << cnt << '\n';
    for(int i = cnt; i >= 1; i--){
        fout << ans[i] << ' ';
    }


    return 0;
}
