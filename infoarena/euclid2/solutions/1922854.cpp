#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid (int a, int b){

  int c;
  while (b){
    c = a%b;
    a = b;
    b = c;
  }
  return a;
}

int main (){

  int t,a,b;
  fin >> t;
  for (int i = 1; i <= t; ++i){
    fin >> a >> b;
    fout << euclid(a,b) << "\n";
  }


}
