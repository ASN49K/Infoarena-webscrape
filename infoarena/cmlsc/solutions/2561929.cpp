#include <fstream>
using namespace std;
int n, m, i, j;
int a[1030][1030];
int a1[1030];
int a2[1030];
int cuvant[1030];
int main(){
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> a1[i];
    }
    for(i = 1; i <= m; i++){
        cin >> a2[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a1[i] == a2[j]){
                a[i][j] = a[i - 1][j - 1] + 1;
            }else{
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    cout << a[n][m] << '\n';
    int lin = n, col = m;
    int k = 0;
    while(a[lin][col] != 0){
        if(a1[lin] == a2[col]){
            cuvant[k] = a1[lin], k++;
            lin--, col--;
        }else{
            if(a[lin - 1][col] > a[lin][col - 1]){
                lin--;
            }else{
                col--;
            }
        }
    }
    for(i = k - 1; i >= 0; i--){
        cout << cuvant[i] << ' ';
    }
    return 0;
}
