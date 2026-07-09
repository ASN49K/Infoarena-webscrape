#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
  int n, m;
  fin >> n >> m;
  vector <int> v(n + 1), w(m + 1), ans;
  for(int i = 1; i <= n; i++)
    fin >> v[i];
  for(int i = 1; i <= m; i++)
    fin >> w[i];
  vector <vector <int>> d(n + 1, vector <int>(m + 1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(v[i] == w[j])
        d[i][j] = 1 + d[i - 1][j - 1];
      else
        d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    }
  }
  fout << d[n][m] << '\n';
  int i = n, j = m;
  while(i > 0 && j > 0){
    while(i > 0 && d[i - 1][j] == d[i][j])
      i--;
    while(j > 0 && d[i][j - 1] == d[i][j])
      j--;
    if(i > 0 && j > 0){
      ans.push_back(v[i]);
      i--;
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  for(auto e : ans)
    fout << e << ' ';
  return 0;
}
