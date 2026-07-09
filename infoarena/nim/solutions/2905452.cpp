#include <iostream>
#include <fstream>
using namespace std;
int t,n,x,xorsum;

ifstream fin("nim.in");
ofstream fout("nim.out");

void solve(){
    fin >> n;
    xorsum = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        xorsum ^= x;
    }
    fout << (xorsum?"DA":"NU") << "\n";
}

int main()
{
    fin >> t;
    while(t--){
        solve();
    }
    return 0;
}
