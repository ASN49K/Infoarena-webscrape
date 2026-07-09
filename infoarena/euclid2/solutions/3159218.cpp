#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b){
  int r;
  if(a < b){
    int aux = a;
    a = b;
    b = aux;
  }

  while( b > 0 ){
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main(){
  int n, a, b;

  ifstream fin ("euclid2.in");
  fin >> n;

  ofstream fout ("euclid2.out");
  for(int i = 0; i < n; i ++){
    fin >> a >> b;
    fout << euclid(a, b) << "\n";
  }
  fin.close();
  fout.close();

  return 0;
}
