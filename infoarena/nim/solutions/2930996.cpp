#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

ifstream fin  ("nim.in");
ofstream fout ("nim.out");

const int MAX_N = 10005;
int n, stones[MAX_N];

int main (){
    ios_base::sync_with_stdio(false);
    fin.tie(nullptr);
    fout.tie(nullptr);

    int teste;
    fin>>teste;
    while(teste--){
        fin>>n;

        int xr = 0;
        for(int i=1; i<=n; i++){
            fin>>stones[i];
            xr ^= stones[i];
        }

        if(xr == 0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
    return 0;
}
