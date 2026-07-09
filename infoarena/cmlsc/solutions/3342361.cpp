#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int N, M, a[1030], b[1030], dp[1030][1040];
vector <int> ans;

void reconstruct(int i, int j)
{
  if(i > 0 and j > 0)
  {
    if(a[i] == b[j]){
      ans.push_back(a[i]);
      reconstruct(i - 1, j - 1);
    }
    else if(a[i] != b[j]){
      if(dp[i][j] == dp[i - 1][j])
        reconstruct(i - 1, j);
      else if(dp[i][j] == dp[i][j - 1])
        reconstruct(i, j - 1);
    }
  }
}

int main()
{
  cin >> N >> M;
  for(int i = 1; i <= N; i++)
    cin >> a[i];
  for(int i = 1; i <= M; i++)
    cin >> b[i];

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= M; j++)
      if(a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  cout << dp[N][M] << '\n';

  reconstruct(N, M);
  reverse(ans.begin(), ans.end());
  for(auto e : ans)
    cout << e << ' ';
  return 0;
}
