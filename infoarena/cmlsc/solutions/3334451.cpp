#include <iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m;
    fin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; ++i) fin >> a[i];
    for(int i = 0; i < m; ++i) fin >> b[i];
    int dp[n][m];
    dp[0][0]= a[0]==b[0];
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
	if(a[i]==b[j] && i > 0 && j > 0) dp[i][j] = dp[i-1][j-1]+1;
	else if(i > 0 && j > 0) dp[i][j] == max(dp[i-1][j], dp[i][j-1]);
	else if(i > 0) dp[i][j] = dp[i-1][j];
	else dp[i][j]=dp[i][j-1];
      }
    }
    cout << dp[n-1][m-1] << '\n';
    int cnt = dp[n-1][m-1];
    for(int i = n-1; i >= 0 && cnt > 0; --i){
      for(int j = m-1; j >= 0 && cnt > 0; --j){
	if(dp[i][j] == cnt) cout << a[i] << ' ', cnt--;
      }
    }
    return 0;
}
