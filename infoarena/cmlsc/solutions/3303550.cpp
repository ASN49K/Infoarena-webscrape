#include <fstream>
#include <vector>

using std::vector;

int n, m;

int main(){
   std::ifstream bem("cmlsc.in");
   std::ofstream kim("cmlsc.out");
   bem >> n >> m;
   vector<int> v1(n), v2(m); 
   vector<vector<int>> dp(n + 1, vector(m + 1, 0));
   for(int i = 0; i < n; i++) bem >> v1[i];
   for(int i = 0; i < m; i++) bem >> v2[i];
   
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(v1[i] == v2[j])
            dp[i + 1][j + 1] = dp[i][j] + 1;
         else
            dp[i + 1][j + 1] = ((dp[i + 1][j] > dp[i][j + 1]) ? dp[i + 1][j] : dp[i][j + 1]); // maximum kereses :)
      }
   }
   int x = n, y = m;
   vector<int> lcs;
   while(x > 0 && y > 0){
      if(v1[x - 1] == v2[y - 1]){
         lcs.push_back(v1[x - 1]);
         x--;
         y--;
      }  else  if(dp[x - 1][y] > dp[x][y - 1])  x--;
      else  y--;
   }
   kim << lcs.size() << '\n';
   for(int i = static_cast<int>(lcs.size()) - 1; i >= 0; i--)
      kim << lcs[i] << ' ';
   kim << '\n';
   bem.close();
   kim.close();
   return 0;
}
