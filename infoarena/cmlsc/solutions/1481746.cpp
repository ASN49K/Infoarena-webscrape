//
//  main.cpp
//  Cel mai lung subsir comun
//
//  Created by Alex Petrache on 05.09.2015.
//  Copyright (c) 2015 Alex Petrache. All rights reserved.
//

#include <iostream>
#include <fstream>
#define N_MAX 1026
using namespace std;

int main(int argc, const char * argv[]) {
//    ifstream f("/Users/alexpetrache/Documents/Programare/Xcode/Arhiva Educationala/Cel mai lung subsir comun/Cel mai lung subsir comun/cmlsc.in");
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n,i,j,x[N_MAX], y[N_MAX], dp[N_MAX][N_MAX];
    f>>m>>n;
    
    for(i=1;i<=m;i++)
        f>>x[i];
    
    for(i=1;i<=n;i++)
        f>>y[i];
    
    for(i=0;i<m;i++)
        dp[0][i]=0;
    
    for(i=0;i<n;i++)
        dp[i][0]=0;
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(y[i]==x[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int lcs[2*N_MAX],k=0;
    i=n;j=m;
    while(i){
        if(y[i]==x[j]){
            lcs[k++]=x[j];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>=dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    
    g<<dp[n][m]<<'\n';
    for(i=dp[n][m]-1;i>=0;i--)
        g<<lcs[i]<<" ";
    return 0;
}
