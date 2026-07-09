#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n,i,j,S,aux;
    fin>>t;
    for(i = 1; i <= t; i++){
        fin>>n;
        S=0;
        for(j = 1; j <= n; j++){
            fin>>aux;
            S = (S^aux);
        }
        if(S == 0){
            fout<<"NU"<<'\n';
        }else{
            fout<<"DA"<<'\n';
        }
    }
    return 0;
}
