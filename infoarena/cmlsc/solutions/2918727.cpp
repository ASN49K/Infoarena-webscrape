#include <fstream>
#include <stack>
#include <cassert>
#define MAX 1025
using namespace std;
 
int dp[MAX][MAX];
stack<int> stk;
 
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("cmlsc.in");
	fout.open("cmlsc.out"); 
	int m, n;
	int a[MAX], b[MAX];
 
	fin >> m >> n;
	for(int i=1; i <= m; ++i){
		fin >> a[i];
	}
	for(int i=1; i <= n; ++i){
		fin >> b[i];
	}
 
	for(int i=1; i <= m; ++i)
		for(int j=1; j <= n; ++j){
 
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			
			if(a[i] == b[j])
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			
		}
 
	fout << dp[m][n] << "\n";
	int i = m, j = n;
	while(dp[i][j]){
		while(dp[i][j] == dp[i - 1][j])
			--i;
 
		while(dp[i][j] == dp[i][j - 1])
			--j;
		stk.push(a[i]);
		assert(a[i] == b[j]);
 
		--i; --j;
	}
 
	while(!stk.empty()){
		fout << stk.top() << " ";
		stk.pop();
	}
 
 
}