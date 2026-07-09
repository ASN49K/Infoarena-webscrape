#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

const int N_MAX = 1024 + 5;
int dp[N_MAX][N_MAX], x1[N_MAX], x2[N_MAX], n1, n2, maxx; 
vector<int> ans;

void print_path(int i, int j){
    if(!i or !j)
        return;

    if(dp[i-1][j] > dp[i][j-1])
        print_path(i-1,j);
    else
        print_path(i, j-1);

     if(x1[i] == x2[j])
        ans.push_back(x1[i]);
}

int main(){
    fin >> n1 >> n2;
    for(int i = 1; i<=n1; ++i)
        fin >> x1[i];
    for(int i = 1; i<=n2; ++i)
        fin >> x2[i];

    for(int i = 1; i<=n1; ++i)
        for(int j = 1; j<=n2; ++j){
            if(x1[i] == x2[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            maxx = max(maxx, dp[i][j]);
        }
    print_path(n1, n2);
    fout << maxx << "\n";
    for(int i = 0; i < ans.size(); ++i)
        fout << ans[i] << " ";
    return 0;
}
// român convertit la moldovenism