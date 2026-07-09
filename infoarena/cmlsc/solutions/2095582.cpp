#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int mat[1025][1025];
int v1[1025], v2[1025];

int main(){
  int n, m;
  in >> n >> m;

  for (int i = 1; i <= n; ++ i)
    in >> v1[i];
  for (int i = 1; i <= m; ++ i)
    in >> v2[i];

  for (int i = 1; i <= n; ++ i){
    for (int j = 1; j <= m; ++ j){
      if (v1[i] == v2[j])
        mat[i][j] = mat[i - 1][j - 1] + 1;
      else
        mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
    }
  }

  int l = mat[n][m];
  int cnt = 1;
  int lasti = 0, lastj = 0;

  out << l << '\n';

  for (int i = 1; i <= n; ++ i){
    for (int j = 1; j <= m; ++ j){
      if (v1[i] == v2[j] && mat[i][j] == cnt && i > lasti && j > lastj){
        out << v1[i] << " ";
        cnt ++;
        lasti = i;
        lastj = j;
      }
    }
  }

  return 0;
}
