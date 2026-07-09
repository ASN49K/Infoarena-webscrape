//
//  main.cpp
//  cmlsc
//
//  Created by Alex Petrache on 30/08/14.
//  Copyright (c) 2014 Alex Petrache. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#define NMAX 1025
using namespace std;

int n=0,m=0;
    int c[NMAX][NMAX];
vector<int> v;

int lungime(int x[NMAX], int y[NMAX]){
    int i,j;
    for(i=0;i<=n;i++)
        c[i][0]=0;
    for(i=0;i<=m;i++)
        c[0][i]=0;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
    return c[n][m];
        
}

string findPath(int x[NMAX], int y[NMAX], int i,int j){
    if(i==0 || j==0)
        return "";
    else if(x[i]==y[j]){
        v.push_back(x[i]);
        return findPath(x, y, i-1, j-1);
    }
    else if(c[i][j-1]>c[i-1][j])
        return findPath(x, y, i, j-1);
    else
        return findPath(x, y, i-1, j);
}

int main(int argc, const char * argv[])
{
    int i,a[NMAX],b[NMAX];
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    g<<lungime(a,b)<<'\n';
    findPath(a, b, n, m);
    for(i=v.size()-1;i>=0;i--)
        g<<v[i]<<" ";
    return 0;
}

