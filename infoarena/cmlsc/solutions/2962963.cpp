#include <bits/stdc++.h>

using namespace std;
 //ifstream fin("rucsac.in");
 //ofstream fout("rucsac.out");

int n, m, a[1025], b[1025], dp[1025][1025], sir[1025], bst;

int main(){ 
    
    //freopen ("file.in", "r", stdin);
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "W", stdout);

    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<m; i++)
        cin>>b[i];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }

    for(int i=n, j=m; i;){
        if(a[i] == b[j]) {
            sir[bst++] = a[i];
            i--;
            j--;
        } else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else 
            i--;
    }
    for(int i=bst-1; i>0; i--)
        cout<<sir[i]<<" ";



    return 0;
}