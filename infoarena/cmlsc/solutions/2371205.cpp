#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1024;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int s1[NMAX], s2[NMAX], dp[NMAX][NMAX], sol[NMAX];
int N1, N2, k;

int read(){
    fin >> N1 >> N2;
    for(int i = 1; i <= N1; i++)
        fin >> s1[i];
    for(int i = 1; i <= N2; i++)
        fin >> s2[i];
}

int afisare(int v[NMAX], int N){
    for(int i = 1; i <= N; i++)
        fout << v[i] << ' ';
}

int main(){

    read();

    for(int i = 1; i <= N1; i++){
        for(int j = 1; j <= N2; j++){
            if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = N1;
    int j = N2;
    while(dp[i][j]){
        if(s1[i] == s2[j]){
            sol[k++] = s1[i];
            i--; j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    fout << dp[N1][N2] << endl;
    while(k--)
        fout << sol[k] << ' ';

    return 0;
}
