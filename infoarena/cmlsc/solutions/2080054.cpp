#include <iostream>
#include <fstream>
#include <stack>

using namespace std;
ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int const nmax = 1024;
#define MIN(a , b) ((a < b) ? a : b)
#define MAX(a , b) ((a < b) ? b : a)
int v[5 + nmax];
int v2[5 + nmax];
int dp[5 + nmax][5 + nmax];
int sum[5 + nmax][5 + nmax];
int indecsi[5 + nmax][5 + nmax];
int indecsj[5 + nmax][5 + nmax];
stack<int> st;

int main()
{
  int n , m;
  in>>n>>m;
  for(int i = 1 ; i <= n ;i++){
		in>>v[i];
  }
  for(int i = 1 ; i <= m ;i++){
		in>>v2[i];
  }
  for(int i = 1 ; i <= n ;i++){
		for(int j = 1 ; j <= m ;j++){
			if(v[i] == v2[j]){
				 dp[i][j] = sum[i - 1][j - 1] + 1;
			}
			sum[i][j] = dp[i][j] ;
			indecsi[i][j] = i;
			indecsj[i][j] = j;
			if(sum[i][j] < sum[i][j - 1] ){
				sum[i][j] = sum[i][j - 1];
				indecsi[i][j] = indecsi[i][j - 1];
			  indecsj[i][j] = indecsj[i][j - 1];
			}
			if(sum[i][j] < sum[i - 1][j]){
				sum[i][j] = sum[i - 1][j];
				indecsi[i][j] = indecsi[i - 1][j];
			  indecsj[i][j] = indecsj[i - 1][j];
			}
		}
  }
  out<<sum[n][m]<<'\n';
  int x , y;
  x = n;
  y = m;
  while(0 < x && 0 < y){
		st.push(v[indecsi[x][y]]);
		int newx , newy;
		newx = indecsi[x - 1][y - 1];
		newy = indecsj[x - 1][y - 1];
		x = newx;
		y = newy;
  }
  while(0 < st.size()){
		out<<st.top()<<" ";
		st.pop();
  }
	return 0;
}
