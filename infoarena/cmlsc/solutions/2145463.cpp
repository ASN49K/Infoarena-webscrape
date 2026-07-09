//
//  main.cpp
//  cmlsc
//
//  Created by Radu Costache on 27/02/2018.
//  Copyright © 2018 Radu Costache. All rights reserved.
//

#include <fstream>
#include <stack>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

char r[1025][1025];
int  dp[1025][1025],n,m,a[1025],b[1025];

void printCMLSC(int i, int j){
    if(i == 0 || j == 0)return;
    switch(r[i][j]){
        case 1:printCMLSC(i - 1, j - 1);g << a[i] << ' ';break;
        case 2:printCMLSC(i - 1, j);break;
        case 3:printCMLSC(i, j - 1);break;
    }
}

void printCMLSCit(){
    stack <int>q;
    int i = n,j = m;
    while(i != 0 && j != 0){
        switch(r[i][j]){
            case 1:q.push(a[i]);--i;--j;break;
            case 2:i--;break;
            case 3:j--;break;
        }
    }
    while(!q.empty())
        g << q.top() << ' ',q.pop();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i,j;
    f >> n >> m;
    for(i = 1 ; i <= n ; ++i)f >> a[i];
    for(i = 1 ; i <= m ; ++i)f >> b[i];
    for(i = 1 ; i <= n ; ++i)
        for(j = 1 ; j <= m ; ++j)
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                r[i][j] = 1;
            }
            else if(dp[i - 1][j] >= dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
                r[i][j] = 2;
            }
            else{
                dp[i][j] = dp[i][j - 1];
                r[i][j] = 3;
            }
    g << dp[n][m] << '\n';
    printCMLSCit();
    g << '\n';
    return 0;
}
