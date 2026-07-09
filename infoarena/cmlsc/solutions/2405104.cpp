#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int x, y;
    scanf("%d %d", &x, &y);
    int v1[x], v2[y];
    for (int i = 0; i < x; ++i)
        scanf("%d", &v1[i]);
    for (int i = 0; i < y; ++i)
        scanf("%d", &v2[i]);
    int dp[x][y];
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(v1[i]==v2[j]){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int count = 0;
     
    int ans[x>y ? x : y];
    for(int i=0; i<x; ++i){
        for(int j=0; j<y; ++j){
            if(dp[i][j]==1){
                if(x>y){
                    ans[count++]=v1[i];
                }
                else
                  ans[count++]=v2[j];
            }
        }
    }
    printf("%d\n", count);
    for(int i=0; i<count; ++i){
        printf("%d ", ans[i]);
    }
}