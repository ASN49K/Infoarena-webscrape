#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int frecv[257], sir[1025];
int main(){
  int j=1, max = 0, m, n, numere, c;
  fin >> m >> n;
  numere = m + n;
  for(int i = 1; i <= numere; ++i){
    fin >> c;
    frecv[c]++;
  }
  for(int i = 1; i <= numere; ++i){
    if(frecv[i] > 1){
      max++;
      sir[j] = i;
      j++;
    }
  }
  j -= 1;
  fout << max << "\n";
  for(int i = 1; i <=j; ++i)
    fout << sir[i]  << " ";
}
