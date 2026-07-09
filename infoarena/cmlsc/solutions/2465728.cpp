#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int frecv[257], sir[1025];
int main(){
  int j=1, max = 0, m, n, numere, c;
  cin >> m >> n;
  numere = m + n;
  for(int i = 1; i <= numere; ++i){
    cin >> c;
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
  cout << max << "\n";
  for(int i = 1; i <=j; ++i)
    cout << sir[i]  << " ";
}
