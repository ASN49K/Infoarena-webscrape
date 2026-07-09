//
//  main.cpp
//  Cmlsc
//
//  Created by Darius Buhai on 26/02/2019.
//  Copyright © 2019 Darius Buhai. All rights reserved.
//

#include <iostream>
using namespace std;

int m, n, maxi = 0, ls;
int a[1025], b[1025], d[1025][1025], c[1025];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            if(d[i][j]>maxi) maxi = d[i][j];
        }
    cout<<maxi<<endl;
    for (int i = m, j = n; i; )
        if (a[i]==b[j]){
            c[ls++] = a[i--];
            j--;
        }
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    for(int i=ls-1;i>=0;i--)
        cout<<c[i]<<" ";
    return 0;
}
