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

int n, m, i, j, k, x, y, a[1001][1001], OK;
vector<int> first;
vector<int> second;
vector<int> rez;

int main()
{
    fin >> n >> m;
    first.push_back(0);
    for(i = 0; i < n; i++)
    {
        fin >> k;
        first.push_back(k);
    }
    second.push_back(0);
    for(i = 0; i < n; i++)
    {
        fin >> k;
        second.push_back(k);
    }
    
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(first[i] == second[j])
                a[i][j] = a[i-1][j-1]+1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
   
    fout << a[n][m] << "\n";
   
    i = n;
    j = m;
    while(a[i][j])
    {
        if(first[i] == second[j])
        {
            rez.push_back(first[i]);
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
    for(i = int(rez.size()-1); i >= 0; i--)
        fout<<rez[i]<<" ";
    
    return 0;
}


