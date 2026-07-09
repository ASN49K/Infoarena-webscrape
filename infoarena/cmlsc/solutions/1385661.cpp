//
//  main.cpp
//  cmlsc
//
//  Created by Alex Rancea on 12/03/15.
//  Copyright (c) 2015 Alex Rancea. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main(int argc, const char * argv[]) {
    int n,m,i,a[1025],b[1025],j,cont=0,c[1025];
    f>>n>>m;
    for(i=1;i<=n;i++){
        f>>a[i];
    }
    for(i=1;i<=m;i++){
        f>>b[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i]==b[j]){
                c[++cont]=a[i];
                
            }
        }
    }
    g<<cont<<endl;
    for(i=1;i<=cont;i++){
        g<<c[i]<<" ";
    }
    return 0;
}
