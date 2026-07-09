#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

ifstream in("lungimesubsircomunmaximal.in");
ofstream out("lungimesubsircomunmaximal.out");

char s1[1005], s2[1005];

int dp[1005][1005];

vector <int> sol;

int main(){
    in.getline(s1, 1005);
    in.getline(s2, 1005);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int s = dp[len1][len2];
    int a = len1, b = len2;
    while(s > 0){
        if(s1[a-1] == s2[b-1]){
            sol.push_back(a-1);
            s--;
            a--;
            b--;
        }else{
            if(dp[a-1][b] == dp[a][b]){
                a--;
            }else{
                b--;
            }
        }
    }
    for(auto it:sol)
        out<<s1[it]<<" ";
    out<<'\n';
    out<<dp[len1][len2];
    return 0;
}
