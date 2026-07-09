//
//  cmlsc.cpp
//  Cel Mai Lung Subsir Comun
//
//  Created by Andrei Constantinescu on 10/20/12.
//  Copyright (c) 2012 Andrei Constantinescu. All rights reserved.
//

#include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int a[1024], b[1024], c[1024][1024], k, s[1024];


int maxim (int a, int b) {
    if (a>b) return a;
    return b;
    
}

int main () {
    int i, j, m ,n;
    f>>m; f>>n;
    for (i=1;i<=m;i++)
        f>>a[i];
    for (j=1;j<=n;j++)
        f>>b[j];
    for (i=1; i<=m; i++)
        for (j=1;j<=n;j++)
            if (a[i]==b[j])
                c[i][j] = c[i-1][j-1]+1;
            else c[i][j] = maxim(c[i-1][j], c[i][j-1]);
    i=m;
    j=n;
    while (i && j) {
        if (a[i]==b[j])
        { s[k++] = a[i]; i--; j--;}
            
        else if (c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    }
    g<<k<<endl;
    for (i=k-1;i>=0; i--)
        g<<s[i];
    
}