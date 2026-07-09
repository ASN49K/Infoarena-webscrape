//
//  main.cpp
//  Cel mai lung subsir comun
//
//  Created by Albastroiu Radu on 11/12/16.
//  Copyright © 2016 Albastroiu Radu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1050][1050],n,m,i,k,j,w[1050],v[1050],rez[1050];

int main()
{
    fin>>n>>m;
    
    for(i=1;i<=n;i++)
        fin>>v[i];
    
    for(i=1;i<=m;i++)
        fin>>w[i];
    
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(v[i]==w[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    
    fout<<a[n][m]<<"\n";

    i=n;j=m;
    while(a[i][j])
    {
        if(v[i]==w[j])
        {
            rez[++k]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    
    for(i=k;i>0;i--)
        fout<<rez[i]<<" ";
    return 0;
}


