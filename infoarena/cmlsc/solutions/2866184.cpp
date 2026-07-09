/*
                         __
                   _.--""  |
    .----.     _.-'   |/\| |.--.
    |    |__.-'   _________|  |_)  _______________
    |  .-""-.""""" ___,    `----'"))   __   .-""-.""""--._
    '-' ,--. `    |Cezar| .---.       |:.| ' ,--. `      _`.
     ( (    ) ) __|  7  |__\\|// _..-- \/ ( (    ) )--._".-.
      . `--' ;\__________________..--------. `--' ;--------'
       `-..-'                               `-..-'
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>

const int N = 1e3 + 5;
int a[N],b[N];
int dp[N][N];

using namespace std;

int main() {
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    a[0] = 0;
    b[0] = 0;
    int n,m;
    in>>n>>m;
    n++;
    m++;
    for(int i=1;i<n;i++)
        in>>a[i];
    for(int i=1;i<m;i++)
        in>>b[i];

    /*
    for(int i=0;i<m;i++)
        out<<b[i]<<' ';
    out<<'\n';
     */
    for(int i=1;i<n;i++){
      //  out<<a[i]<<' ';
        for(int j=1;j<m;j++){
            dp[i][j] = (a[i] == b[j]) * (1 + dp[i-1][j-1]) +  (a[i] != b[j])*(max(dp[i-1][j],dp[i][j-1]));
            //out<<dp[i][j]<<' ';
        }
       // out<<'\n';
    }

    stack <int> s;
    int x = n-1,y = m-1;
    while(dp[x][y] != 0){
        while(dp[x][y-1] == dp[x][y])
            y--;
        while(dp[x-1][y] == dp[x][y])
            x--;
        s.push(b[y]);
       // cout<<b[y]<<' ';
        x--;
        y--;
    }
    out<<s.size()<<'\n';
   while(!s.empty()){
       out<<s.top()<<' ';
       s.pop();
   }
    return 0;
}
