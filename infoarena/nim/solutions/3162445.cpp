#include<bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n, t, x, sol;
int main(){
    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>t;
        for(int j=1; j<=t; j++){
            fin>>x;
            sol ^= x;
        }
        fout<<(sol>0?"DA\n":"NU\n");
        sol = 0;
    }
}
