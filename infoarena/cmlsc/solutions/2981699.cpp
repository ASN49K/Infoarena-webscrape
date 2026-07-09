#include <fstream>
#include <cmath>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int x[1300][1300];
int main(){
    int n , m;
    int a[1300] , b[1300];
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if (a[i] == b[j]){
                x[i][j] = x[i - 1][j - 1] + 1;
            }
            else
                x[i][j] = max(x[i - 1][j] , x[i][j - 1]);
        }
    }
    int ans[1300] , k = 0;
    int i = m, j = n;
    while (i > 1 or j > 1){
        if (a[i] == b[j]){
            ans[++k] = a[i];
            i--;
            j--;
        }
        else if (x[i - 1][j] > x[i][j - 1])
            i--;
        else
            j--;
    }
    cout << k << '\n';
    for(int ii = k; ii > 0; ii--)
        cout << ans[ii] << ' ';
    cin.close();
    cout.close();
}