#include <fstream>
#define int long long
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t;
int gcd(int a, int b){
    while(a!=b)
    if(a>b)
        a -= b;
    else
        b -= a;
    return a;
}

signed main(){
    fin >> t;
    for(int i=1;i<=t;++i)
    {
        fin >> a >> b;

        fout << gcd(a,b) << '\n';
    }
}
