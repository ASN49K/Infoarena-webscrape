#include <fstream>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int Nmax = 1030;
int a[Nmax],b[Nmax],dp[Nmax][Nmax];
pair<int, int> prv[Nmax][Nmax];
stack<int> st;

int main()
{
    int n,m,i,j;
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(i=1;i<=m;i++)
        fin >> b[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            if(dp[i][j] == dp[i][j-1])
                prv[i][j] = prv[i][j-1];
            else if(dp[i][j] == dp[i-1][j])
                prv[i][j] = prv[i-1][j];
            if(a[i] == b[j] && dp[i-1][j-1]+1>dp[i][j]){
                dp[i][j] = dp[i-1][j-1]+1;
                prv[i][j] = {i, j};
            }
        }
    }
    fout << dp[n][m] << '\n';
    i = prv[n][m].first; j = prv[n][m].second;
    while(i>0 && j>0){
        int i0 = i, j0 = j;
        st.push(a[i0]);
        i = prv[i0-1][j0-1].first;
        j = prv[i0-1][j0-1].second;
    }
    while(!st.empty()){
        fout << st.top() << " ";
        st.pop();
    }
    return 0;
}
