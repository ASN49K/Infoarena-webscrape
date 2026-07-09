//
//  main.cpp
//  cmlsc
//
//  Created by Toie Vlad on 16/11/2020.
//

#include <iostream>
#define MAX_N 1025

using namespace std;

int v[MAX_N], w[MAX_N], d[MAX_N][MAX_N], tot, s[MAX_N];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++) {
        cin>>v[i];
    }
    for(int i = 1; i<=m; i++) {
        cin>>w[i];
    }
    for(int i = 1; i<=n; i++) {
        for(int j =1; j<=m; j++) {
            d[i][j] = max(d[i-1][j], d[i][j-1]);
            if(v[i] == w[j]) {
              d[i][j] = max(d[i][j], 1 + d[i-1][j-1]);
            }
        }
    }
    cout<<d[n][m]<<endl;
    while(d[n][m] != 0)
    {
        if(w[m] == v[n])
        {
            s[++tot] = v[n];
            m--;
            n--;
        }
        else
        {
            if(d[n-1][m] < d[n][m-1])
                m--;
            else
                n--;
        }
    }
    for(int i = tot; i>0; i--) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}
