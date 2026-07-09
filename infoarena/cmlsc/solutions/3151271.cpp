#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int nmax = 1030;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[nmax][nmax], v1[nmax], v2[nmax];
vector<int> a;
int n,m;

//solutia cu programare dinamica folosind o matrice dp care merge pe diagonala sau in sus sau jos
/*7 6 
1 4 5 9 5 0 10 
1 5 9 0 5 6 */

int main(){
    f >> n >> m;
    for(int i = 1; i <= n; i++){
        f >> v1[i];
    }
    for(int i = 1; i <= m; i++){
        f >> v2[i];
    }
    for(int i = n; i >= 1; i--){
      for(int j = m; j >= 1; j--){
        if(v1[i] == v2[j]){
          dp[i][j] = 1 + dp[i + 1][j + 1];
         // a.push_back(v1[i]);
        }
        else{
          dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }

    // aici vom reconstitui drumul prin matrice ca sa calcualm vectorul cu subsecventa ceruta
    //va fi cam acelasi principiu ca la matrice de cum ne consideram drumul
    int i = n, j = m;
    while(i != 0 || j != 0){
        if(v1[i] == v2[j]){
            a.push_back(v1[i]);
            i--;
            j--;
        }
        else {
            
            if(dp[i - 1][j] < dp[i][j - 1]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    g << dp[1][1] << '\n';
  //  reverse(a.begin(), a.end());
    for(int i = a.size() - 1; i >= 0; i--){
      g << a[i] << ' ';
    }
}