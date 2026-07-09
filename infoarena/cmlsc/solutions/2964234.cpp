#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1025;
int dp[N][N] , v1[N] , v2[N];

void refac_traseu(int i , int j){
    if(i == 0 || j == 0){
        return;
    }
    if(v1[i] == v2[j]){
        refac_traseu(i - 1 , j - 1);
        out << v1[i] << ' ';
    }
    else{
        if(dp[i - 1][j] < dp[i][j - 1])
            refac_traseu(i , j - 1);
        else{
            refac_traseu(i - 1 , j);
        }
    }
}
int main(){

    int n , m;
    in >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        in >> v1[i];
    }
    for(int i = 1 ; i <= m ; i++){
        in >> v2[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(v1[i] != v2[j]){
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
            else{
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    out << dp[n][m] << '\n';
    refac_traseu(n , m);
    in.close();
    out.close();
}
