#include <bits/stdc++.h>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

const int NMAX = 1024;

int a[NMAX+1], b[NMAX+1];
int dp[NMAX+1][NMAX+1];

//dp[i][j] = lungimea celui mai lung subsir luand in calcul elementele pana la i din a si pana la j din b

void refac(int i, int j){
    
    if(i == 0 or j == 0)
        return;
        
    if(a[i] == b[j]){
        
        refac(i-1, j-1);
        
        g << a[i] << ' ';
        
    }else{
        
        if(dp[i-1][j] >= dp[i][j-1]) // mai scad in a
            refac(i-1, j);
            
        else refac(i, j-1);// mai scad in b;
        
    }
    
}

int main()
{
    
    int n, m;
    f >> n >> m;
    
    for(int i=1; i<=n; i++)
        f >> a[i];
        
    for(int i=1; i<=m; i++)
        f >> b[i];
        
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
        
    for(int j=0; j<=m; j++)
        dp[0][j] = 0;
        
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            
            //1 : a[i] == b[j] adica crestem cu 1 element
            
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
                
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            
        }
        
    g << dp[n][m] << "\n";
    
    refac(n, m);
                
      
    
    
    

    return 0;
}