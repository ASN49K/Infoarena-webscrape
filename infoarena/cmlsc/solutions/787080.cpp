#include<cstdio>
#include<cassert>
#include<vector>

using namespace std;

const int kcon = 1050;

class cmlsc{
private:

  int size1, size2, s1[1026], s2[1026];

  int dp[1026][1026], recon[1126][1126];

  int line(int x){
    return x / kcon;
  }

  int col(int x){
    return x % kcon - 1;
  }

  int num(int x, int y){
    return x * kcon + y + 1;
  }

public:

  void read(){
    assert(freopen("cmlsc.in", "r", stdin));

    scanf("%d%d", &size1, &size2);

    for(int i = 0; i < size1; ++i)
      scanf("%d", &s1[i]);

    for(int i = 0; i < size2; ++i)
      scanf("%d", &s2[i]);

  }

  void solve(){
    for(int i = 0; i < size1; ++i)
      for(int j = 0; j < size2; ++j)
        if(s1[i] == s2[j])
          if(i > 0 && j > 0){
            dp[i][j] = dp[i - 1][j - 1] + 1;
            recon[i][j] = num(i - 1, j - 1);
          }
          else{
            dp[i][j] = 1;
            recon[i][j] = 1040 * 1040;
          }
        else{
          if(i > 0){
            dp[i][j] = dp[i - 1][j];
            recon[i][j] = num(i - 1, j);
          }
          if(j > 0)
            if(dp[i][j] < dp[i][j - 1]){
              dp[i][j] = dp[i][j - 1];
              recon[i][j] = num(i, j - 1);
          }
        }
  }

  void write(){
    assert(freopen("cmlsc.out", "w", stdout));

    int ln, cl, mx = -1;

    for(int i = 0; i < size1; ++i){
      for(int j = 0; j < size2; ++j){
        //printf("%d ", dp[i][j]);
        if(dp[i][j] > mx && s1[i] == s2[j]){
          mx = dp[i][j];
          ln = i;
          cl = j;
        }
      }
      //printf("\n");
    }

    printf("%d\n", mx);

    vector<int> ans;

    do{
      if(s1[ln] == s2[cl])
        ans.push_back(s1[ln]);

      int aux = ln;
      ln = line(recon[ln][cl]);
      cl = col(recon[aux][cl]);
    }while(recon[ln][cl]);

    for(int i = ans.size() - 1; i >= 0; -- i)
      printf("%d ", ans[i]);

  }

} t;

int main(){
  t.read();
  t.solve();
  t.write();
  return 0;
}
