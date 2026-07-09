#include <iostream>
#include <fstream>

using namespace std;

int T, A, B;

int euclid(int a, int b){
  if(!b) return a;
  return euclid(b, a % b);
}

int main(){
  ifstream fin ("euclid2.in");
  ofstream fout ("euclid2.out");

  fin >> T;
  for(; T; --T){
    fin >> A >> B;
    fout << euclid(A, B) << '\n';
  }

  return 0;
}
