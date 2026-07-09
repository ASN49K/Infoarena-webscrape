#include <fstream>
#define N 1030
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int matrice[N][N],a[N],b[N],nr[N];
int main()
{
    int n,j,i,m;
    cin >> n >> m;
    for(i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(i = 1;i <= m;i++){
        cin >> b[i];
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(a[i] == b[j]){
                matrice[i][j] = matrice[i-1][j-1] + 1;
            }else{
                matrice[i][j] = max(matrice[i-1][j],matrice[i][j-1]);
            }
        }
    }
    i = n;
    j = m;
    int varf = 0;
    while(i > 0 &&  j > 0){
        if(a[i] == b[j])
        {
            nr[++varf] = a[i];
            i--;
            j--;
        }else if(matrice[i][j] == matrice[i-1][j])
        {
            i--;
        }else{
            j--;
        }
    }
    cout << matrice[n][m]<< "\n";
    for(i = varf;i > 0;i--){
        cout << nr[i] << " ";
    }
    return 0;
}
