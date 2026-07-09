//
//  main.cpp
//  cmmdc
//
//  Created by Alex Petrache on 04.09.2015.
//  Copyright (c) 2015 Alex Petrache. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b){
    if(a%b==0)
        return b;
    return cmmdc(b,a%b);
}

int main(int argc, const char * argv[]) {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    int n;
    int a,b;
    for(int i=0;i<n;i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
