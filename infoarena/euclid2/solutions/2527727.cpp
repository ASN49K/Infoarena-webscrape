#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b, r;

int main(){
    fin>>n;
    while(n--){
        fin>>a>>b;
        while(b){
            r = a % b;
            a = b;
            b = r;
        }
        fout<<a<<endl;
    }
    return 0;
}
