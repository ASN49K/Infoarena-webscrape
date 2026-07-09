#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
  int N, M, l = 0;
  int o[1025];
  int A[1025];
  int B[1025];
  int d[1025][1025] = {};
  fin >> N >> M;
  for(int i = 1; i <= N; i++){
    fin >> A[i];
  }
  for(int j = 1; j <= M; j++){
    fin >> B[j];
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      d[i][j] = max(d[i - 1][j], d[i][j - 1]);
      if(A[i] == B[j]){
        d[i][j] = max(d[i][j], 1 + d[i - 1][j - 1]);
      }
    }
  }
  fout << d[N][M]<< "\n";
  int i = N;
  int j = M;
  while(d[i][j] > 0){

    while(d[i][j] == d[i - 1][j]){
      i--;
    }
    while(d[i][j] == d[i][j - 1]){
      j--;
    }
    l++;
    o[l] = A[i];
    i--;
    j--;
    
  }
  for(int i = l; i >= 1; i--){
    fout << o[i] << " ";
  }
} 