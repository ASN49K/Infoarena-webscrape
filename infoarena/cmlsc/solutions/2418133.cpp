#include <fstream>
#include <iostream>
#define lmax 1030

using namespace std;

//ifstream fin("date.in");
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[lmax], b[lmax], v[lmax][lmax];

int lung_max(){
    for(int i = 0; i < n; ++i)
        v[i][0] = 0;
    for(int i = 0; i < m; ++i)
        v[0][i] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i - 1] == b[j - 1])
                v[i][j] = v[i - 1][j - 1] + 1;
            else
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
    return v[n][m];
}

void solve(){
    int sol[lmax], k = 0, i = n, j = m;
    while(i > 0 && j > 0){
        if(v[i][j] == v[i][j - 1])
            j--;
        else if(v[i][j] == v[i - 1][j])
            i--;
        else{
            sol[k++] = a[i - 1];
            i--; j--;
        }
    }
    for(int i = k - 1; i >= 0; --i)
        fout << sol[i] << " ";
}

int main(){

    fin >> n >> m;
    for(int i = 0; i < n; ++i)
        fin >> a[i];
    for(int i = 0; i < m; ++i)
        fin >> b[i];
    fout << lung_max() << '\n';
    solve();
    fin.close();
    fout.close();
    return 0;
}
