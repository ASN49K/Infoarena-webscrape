#include <iostream>
#include <cstdio>
#include <vector>

#define N 1024

using namespace std;

int a[N],b[N],d[N][N];

int main(){
  
  int m,n;
  freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
  
  cin>>n>>m;
  for(int i = 1;i <= n;i++)
    cin>>a[i];
  for(int i = 1;i <= m;i++)
    cin>>b[i];
  
  vector<int> sol;
  
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= m;j++)
      if(a[i] == b[j])
	d[i][j] = 1 + d[i-1][j-1];
      else 
	d[i][j] = max(d[i][j-1],d[i-1][j]);
  
  cout<<d[n][m]<<endl;
  
  for(int i = n,j = m;i;){
    if(a[i] == b[j]){
      sol.push_back(a[i]);
      i--;j--;
    }
    else if(d[i-1][j] < d[i][j-1])
	    j--;
	  else 
	    i--;
  }
  for(int i = sol.size()-1;i > -1;i--)
    cout<<sol[i]<<" ";
  
  return 0;
  
}
  
  