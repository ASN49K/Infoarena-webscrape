#include <iostream>
#include <fstream>

using namespace std;

int a, b, big_size;
int va[1026], vb[1026];
int dp[1026][1026];
int sol[1026];

int main() {

  ifstream fin("cmlsc.in");
  fin >> a >> b;
  for(int i = 0; i < a; i++) {
    fin >> va[i];
  }
  for(int i = 0; i < b; i++) {
    fin >> vb[i];
  }
  fin.close();

  for(int i = 1; i <= a; i++) {
    for(int j = 1; j <= b; j++) {
      if(va[i-1] == vb[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  ofstream fout("cmlsc.out");

  int x = dp[a][b];
  int y = x;

  while(a > 0 && b > 0) {
    if(va[a-1] == vb[b-1]){
      sol[--x] = va[a-1];
      a--;
      b--;
    }
    else if(dp[a][b] == dp[a-1][b]) {
      a --;
    }
    else {
      b --;
    }
  }

  fout << y << endl;
  for(int i = 0; i < y; i++) {
    fout << sol[i] << " ";
  }
  fout.flush();
  fout.close();

  return 0;
}
