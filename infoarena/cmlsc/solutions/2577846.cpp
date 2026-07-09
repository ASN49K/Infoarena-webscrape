//
//  main.cpp
//  Longest Common SUbsequence
//
//  Created by Razvan Vranceanu on 09/03/2020.
//  Copyright © 2020 Razvan Vranceanu. All rights reserved.
//

#include <bits/stdc++.h>
//#include "/Users/razvanvranceanu/stdc++.h"
#define MAX 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int d[MAX][MAX], sir[MAX], k;
void citire(int &n, int &m , int a[MAX], int b[MAX])
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int j=1;j<=m;j++)
        f>>b[j];
}
int main()
{
    int n, m, a[MAX]={0}, b[MAX]={0};
    citire(n, m, a, b);
    
    //initializare
    for(int i=1;i<=n;i++)
        d[i][0]=0;
    for(int i=1;i<=m;i++)
        d[0][m]=0;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] =max(d[i][j-1], d[i-1][j]);
    g<<d[n][m]<<'\n';
    
    int i = n, j=m;
    while(i>=1 && j>=1)
    {
        if(d[i][j]!= d[i][j-1] && d[i][j]!=d[i-1][j])
        {
            sir[++k]=a[i];
            i--;
            j--;
        }
        else if (d[i][j] == d[i][j-1])
            j--;
        else i--;
    }
    for(int i=k;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
