#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025], b[1025], dp[1025][1025];

void drumul(int i, int j){
      if(i == 0 || j == 0){
        return;
      }
      if(a[i] == b[j]){
        drumul(i-1, j-1);
        out << a[i] << " ";
      }else if(dp[i-1][j] > dp[i][j-1]){
        drumul(i-1, j);
      }else{
        drumul(i, j-1);
      }
}

int main()
{
    int n, m;
    in >> m >> n;
    for(int i = 1; i <= m; i++){
      in >> a[i];
    }
    for(int i = 1; i <= n; i++){
      in >> b[i];
    }
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
          if(a[i] == b[j]){
            dp[i][j] = 1 + dp[i-1][j-1];
          }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
      }
    }
    out << dp[m][n] << "\n";
    drumul(m, n);
    return 0;
}
