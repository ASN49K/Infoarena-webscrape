#include <fstream>
#include <queue>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[1025][1025];
int v1[1025], v2[1025];
queue <int>coada;
int cnt;
int m, n;
int last;

int main(){
  in >> m >> n;

  for (int i = 1; i <= m; ++ i)
    in >> v2[i];
  for (int i = 1; i <= n; ++ i)
    in >> v1[i];


  for (int i = 1; i <= n; ++ i){
    for (int j = 1; j <= m; ++ j){

      dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);

      if (v1[i] == v2[j]){
        dp[i][j] ++;

        if (dp[i][j] > cnt){
          cnt ++;
          if (min(i, j) > last){
            if (i <= j)
              coada.push(v1[i]);
            else
              coada.push(v2[j]);
            last = min(i, j);
          }
        }
      }
    }
  }

  out << dp[n][m] << '\n';

  while (coada.size()){
    out << coada.front() << " ";
    coada.pop();
  }

  return 0;
}
