#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ifstream fin("nim.in");
ofstream fout("nim.out");
void tc(){
    ll n,Xor=0;
    fin>>n;
    while(n--){
        ll x;
        fin>>x;
        Xor^=x;
    }
    fout<<(Xor?"DA":"NU")<<'\n';
}
int main()
{
    ll t; fin>>t; while(t--)
        tc();
    return 0;
}
