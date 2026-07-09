#include<fstream>

using namespace std;

#define MAX 1024

int* solve(int *A, int n, int *B, int m){
  int* sol  = new int[n];
  int* help = new int[m];

  for(int i = 0; i < m; i++)
    help[i] = 0;

  for(int i = 0; i < n; i++)
    sol[i] = MAX;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if (B[j] == A[i] && help[j] == 0){
        sol[i] = j;
        help[j] = 1;
        break;
      }

  for(int i = n - 2; i >= 0; i--)
    if (sol[i] > sol[i + 1])
      sol[i] = sol[i+1];

  delete help;
  return sol;
}

int main(){

  ifstream f("cmlsc.in");
  ofstream g("cmlsc.out");
  
  int n, m;
  f >> n >> m;
  int *A = new int[n], *B = new int[m];
  for(int i = 0; i < n; i++)
    f >> A[n-i-1];
  for(int i = 0; i < m; i++)
    f >> B[m-i-1];

  int *sol = solve(A,n,B,m);
  int max = MAX, k = 0;
  for(int i = n-1; i >= 0; i--)
    if (sol[i] < max){
      k++;
      max = sol[i];
    }
  g << k << '\n';
  max = MAX;
  for(int i = n-1; i >= 0; i--)
    if (sol[i] < max){
      max = sol[i];
      g << B[sol[i]] << " ";
    }

  delete sol;
  delete A;
  delete B;  
  f.close();
  g.close();
  return 0;
}
