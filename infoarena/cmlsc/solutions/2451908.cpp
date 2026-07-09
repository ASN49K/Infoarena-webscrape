#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");
int dp[1025][1025];
std::vector<int>a,b,sol;

int main(){
    a.push_back(0);
    b.push_back(0);
    int n,m;
    in>>n>>m;
    for(int i=0,aux;i<n;i++)
        in>>aux,a.push_back(aux);
    for(int i=0,aux;i<m;i++)
        in>>aux,b.push_back(aux);

    for(int i=1;i<a.size();i++)
        for(int j=1;j<b.size();j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
    int caut=dp[a.size()-1][b.size()-1];
    int x=a.size()-1,y=b.size()-1;
    while(1){
        if(a[x]==b[y]){
            sol.push_back(a[x]),x--,y--;
            if(dp[x+1][y+1]==1)
                break;
        }
        else
            if(dp[x][y]==dp[x-1][y])
                x--;
            else
                y--;
    }
    std::reverse(sol.begin(),sol.end());
    out<<sol.size()<<'\n';
    for(int &x:sol)
       out<<x<<" ";
    return 0;
}
