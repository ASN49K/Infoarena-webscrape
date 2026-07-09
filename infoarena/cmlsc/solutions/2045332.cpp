#include <fstream>
#include <stack>

#define NMax 1024
#define FOR(i , x , y) for(int i = x; i <= y ; i++)

using namespace std;

int x[NMax], y[NMax] , m , n , dp[NMax][NMax];
stack<int> sir;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin>>m>>n;
    FOR(i , 1 , m){
        fin>>x[i];
    }
    FOR(i , 1 , n){
        fin>>y[i];
    }

    FOR(i , 1 , m)
        FOR (j , 1 , n){
            if(x[i] == y[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    for(int i = m , j = n ; i;){
        if(x[i] == y[j]){
            sir.push(x[i]);
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i --;
            }
            else{
                j--;
            }
        }
    }
    fout<<sir.size()<<'\n';
    while(!sir.empty()){
        fout<<sir.top()<<' ';
        sir.pop();
    }
    return 0;
}
