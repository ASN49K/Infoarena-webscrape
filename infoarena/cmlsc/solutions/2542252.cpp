#include <fstream>
#include <iostream>
#include <vector>
#define NMAX 1024 //Maximum dim
#define MAX(A, B) A >= B ? A : B

std::vector<short> a(NMAX + 1); //First vector
std::vector<short> b(NMAX + 1); //Second vector
int n, m;
int dp[NMAX + 1][NMAX + 1]; //dp matrix

std::ifstream f("cmlsc.in");
std::ofstream g("cmlsc.out");

//read data
void read_data(){
    f >> n >> m;
    for(int i = 0; i<n; i++){
        f >> a[i];
    }
    for(int i = 0; i<m; i++){
        f >> b[i];
    }
}


//solve dp
void solve(){
    int val = 0;
    for(int i = 0; i<n; i++){
        if(a[i] == b[0]){
            val = 1;
        }
        dp[i][0] = val;
    }
    val = 0;
    for(int i = 0; i<m; i++){
        if(b[i] == a[0]){
            val = 1;
        }
        dp[0][i] = val;
    }
  
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void trace(int sol, int i, int j){
    if(sol){
        if(dp[i - 1][j] == sol){
            trace(sol, i - 1, j);
        }else if(dp[i][j - 1] == sol){
            trace(sol, i, j - 1);   
        }else{
            trace(sol - 1, i - 1, j - 1);
            g << a[i] << ' ';
        }
    }
}

int main(){
    read_data();
    solve();
    g << dp[n - 1][m - 1] << '\n';
    trace(dp[n - 1][m - 1], n - 1, m - 1);
    return 0;
}