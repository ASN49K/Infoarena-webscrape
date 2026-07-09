#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b){
  if(a % b == 0) return b;
  else return euclid(b, a % b);
}

int main(){
  ifstream fin ("euclid2.in");
  ofstream fout ("euclid2.out");

  int t, a, b;

  fin >> t;
  for(int i = 0; i < t; i++){
    fin >> a >> b;
    fout << euclid(a, b) << endl;
  }
  
  
  return 0;
}
