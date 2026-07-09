//
//  main.cpp
//  euclid
//
//  Created by Alex Rancea on 20/02/15.
//  Copyright (c) 2015 Alex Rancea. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main(int argc, const char * argv[]) {
    int t;
    f>>t;
    int i,x,imp,a,b;
    for(i=1,imp=0;i<=t;i++,imp=0){
        f>>a>>b;
        x = min(a,b);
        for(;x>=2&&a>1&&b>1;x--){
            if(a%x==0&&b%x==0){
                a /= x;
                b /= x;
                imp += x;
            }
        }if(imp==0){
            g<<"1\n";
        }else{
        g<<imp<<"\n";
        }
    }
    return 0;
}
