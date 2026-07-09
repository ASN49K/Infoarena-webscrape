#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int q, a, b, r;

int main(){
    fin>>q;
    while(q--){
        fin>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
}
