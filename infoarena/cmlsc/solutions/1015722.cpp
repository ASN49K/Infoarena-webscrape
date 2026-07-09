#include<iostream>
#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void solve(int *A, int n, int *B, int m){
  int** sol;
  sol = new int*[n+1];
  for(int i = 0; i <= n; i++)
    sol[i] = new int[m+1];
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      if(A[i-1] == B[j-1])
        sol[i][j] = sol[i-1][j-1] + 1;
      else
        sol[i][j] = sol[i-1][j] > sol[i][j-1] ? sol[i-1][j] : sol[i][j-1];

  g << sol[n][m] << '\n';
  
  int i = n, j = m, max = sol[n][m];
  while(max > 0){
    if (A[i-1] == B[j-1]){
      g << A[i-1] << " ";
      max--;
      i--;
      j--;
    }
    else if (sol[i-1][j] == max)
      i--;
    else
      j--;
    
  }
  delete sol;
}

int main(){
  
  int n, m;
  f >> n >> m;
  int *A = new int[n], *B = new int[m];
  for(int i = 0; i < n; i++)
    f >> A[n-i-1];
  for(int i = 0; i < m; i++)
    f >> B[m-i-1];

  solve(A,n,B,m);

  delete A;
  delete B;  
  f.close();
  g.close();
  return 0;
}
