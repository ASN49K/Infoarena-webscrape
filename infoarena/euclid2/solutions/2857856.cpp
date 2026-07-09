#include <fstream>

#define ll long long

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

ll cmmdc(ll a, ll b){
  ll r;
  while(b){
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main(){
  ll T;

  fin >> T;

  for(ll i = 1, a, b; i <= T; ++i){
    fin >> a >> b;
    fout << cmmdc(a, b) << "\n";
  }

  return 0;
}

