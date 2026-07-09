#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;
int gcd(int a, int b){
    if(!b) return a;
    if(a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}
int main(){
    for(fin >> t; t; t--){
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }
    return 0;
}
