//
//  main.cpp
//  001
//
//  Created by adrian ilisei on 29/06/2018.
//  Copyright © 2018 adrian ilisei. All rights reserved.
//
// --- Cel mai lung subsir comun ---

#include <fstream>
using namespace std;

int m, n;
short v1[1024], v2[1024];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void cmlsc()
{
    int L[m+1][n+1];
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0) L[i][j] = 0;
            else
                if(v1[i-1] == v2[j-1]) L[i][j] = L[i-1][j-1] + 1;
                else L[i][j] = L[i-1][j] > L[i][j-1] ? L[i-1][j] : L[i][j-1] ;
        }
    }
    fout<<L[m][n]<<"\n";
    int x = m, y = n, cursor = 0;
    short subsrt[1024];
    while(x > 0 && y > 0)
    {
        if(v1[x-1] == v2[y-1])
        {
            subsrt[cursor++] = v1[x-1];
            x--;
            y--;
        } else
            if(L[x - 1][y] > L[x][y - 1]) x--;
            else y--;
    }
    for(int i = cursor - 1; i >= 0; i--) fout<<subsrt[i]<<" ";
}

int main()
{
    fin>>m>>n;
    for(int i = 0; i < m; i++) fin>>v1[i];
    for(int i = 0; i < n; i++) fin>>v2[i];
    cmlsc();
    return 0;
}
