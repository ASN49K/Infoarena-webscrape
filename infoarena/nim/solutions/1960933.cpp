#include <fstream>

using namespace std;

int main(){
  ifstream cin("nim.in");
  ofstream cout("nim.out");
int i,t,n,x;
  cin >> t;
  while(t){
    cin >> n;
    int s = 0;
    for(i = 1 ; i <= n ; ++i)
      cin >> x,s ^= x;
    if(s)cout << "DA\n";
    else cout << "NU\n";
    --t;
  }
  return 0;
}
