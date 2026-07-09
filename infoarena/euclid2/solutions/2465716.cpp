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
    while(a != b){
      if(a > b)
        a-=b;
      else if(b > a)
        b-=a;
    }
    fout << a << "\n";
  }
}
