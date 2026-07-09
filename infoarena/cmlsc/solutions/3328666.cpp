//
//  main.cpp
//  cmls
//
//  Created by Rei on 09.12.2025.
//

#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n, m, a[1024], b[1024], d[1030][1030];
int v[101];
int main()
{
    f>>n>>m;
    
    for (int i = 1; i <= n; ++i){
        f>>a[i];
    }
    
    for (int i = 1; i <= m; ++i){
        f>>b[i];
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }
    int mx = d[n][m];
    int i=n,j=m,k=0;
    while(mx>0)
    {
        if(a[i]==b[j])
        {
            k++;
            v[k]=a[i];
            i--;
            j--;
            mx--;
        }
        else{
            if(d[i-1][j]==mx && i>1)
                i--;
            else
                j--;
            
                
        }
    }
    g<<d[n][m]<<'\n';
    for(int l=k;l>=1;l--)
    {
        g<<v[l]<<" ";
    }
}
