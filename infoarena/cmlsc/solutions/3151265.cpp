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


int main(){
    f >> n >> m;
    for(int i = 1; i <= n; i++){
        f >> v1[i];
    }
    for(int i = 1; i <= m; i++){
        f >> v2[i];
    }
    for(int i = n + 1; i > 1; i--){
      for(int j = m + 1; j > 1; j--){
        if(v1[i - 1] == v2[j - 1]){
          dp[i - 1][j - 1] = 1 + dp[i][j];
          a.push_back(v1[i - 1]);
        }
        else{
          dp[i - 1][j - 1] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    g << dp[1][1] << '\n';
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
      g << a[i] << ' ';
    }
}