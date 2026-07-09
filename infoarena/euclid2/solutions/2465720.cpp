#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
  int nrPerechi, a, b;
  fin >> nrPerechi;
  for(int i = 1; i <= nrPerechi; ++i){
    fin >> a;
    fin >> b;
    while(b != 0){
      int rest = a % b;
      a = b;
      b = rest;
    }
    fout << a << "\n";
  }
}
