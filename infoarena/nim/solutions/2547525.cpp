#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int v[10006];

int main()
{
    int n,t,i,j,S;
    fin>>t;
    for(i = 1; i <= t; i++){
        fin>>n;
        fin>>v[1];
        S=v[1];
        for(j = 2; j <= n; j++){
            fin>>v[1];
            S^=v[1];
        }
        if(S == 0){
            fout<<"NU"<<'\n';
        }else{
            fout<<"DA"<<'\n';
        }
    }
    return 0;
}
