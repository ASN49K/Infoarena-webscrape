#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

vector<int> v(257);

int main(){
  int n, m, temp, count = 0;
  cin >> n >> m;

  for (int i = 0; i < n; i++){
    cin >> temp;
    v[temp]++;
  }

  for (int i = 0; i < m; i++){
    cin >> temp;
    v[temp]++;
  }

  for (int i = 0; i < 257; i++){
    if (v[i] != 0 && v[i] % 2 == 0){
      count++;
    }
  }

  cout << count << '\n';

  for (int i = 0; i < 257; i++){
    if (v[i] != 0 && v[i] % 2 == 0){
      cout << i << ' ';
    }
  }

  cout << endl;
  
  return 0;
}
