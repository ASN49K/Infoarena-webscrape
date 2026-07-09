#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;
int main(){
    fin >> t;
    while(t--){
        fin >> a >> b;
        while(b != 0){
            int r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
    return 0;
}
