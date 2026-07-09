#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1025;

int m, n, a[NMAX], b[NMAX], dp[NMAX][NMAX], cmlsc[NMAX];

int main(){
    fin >> m >> n;
    for(int i=1; i<=m; i++){
        fin >> a[i];
    }
    for(int i=1; i<=n; i++){
        fin >> b[i];
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            //dp[i][j]=cmlsc pentru a1->ai si b1->bj
            if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]); 
        }
    }
    
    int k=0, i=m, j=n;
    while(i && j){
        if(a[i]==b[j]){
            cmlsc[++k]=a[i];
            i--; j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }

    fout << k << '\n';
    for(i=k; i>0; i--){
        fout << cmlsc[i] << ' ';
    }
}