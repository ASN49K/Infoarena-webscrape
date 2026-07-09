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

struct nr{
    int a;
    int b;
};

int main(int argc, const char * argv[]) {
    int t;
    f>>t;
    int i,x,imp;
    nr *a = new nr[t];
    for(i=1,imp=0;i<=t;i++,imp=0){
        f>>a[i].a>>a[i].b;
        x = min(a[i].a,a[i].b);
        for(;x>=2;x--){
            if(a[i].a%x==0&&a[i].b%x==0&&a[i].a>1&&a[i].b>1){
                a[i].a /= x;
                a[i].b /= x;
                imp += x;
            }
        }if(imp==0){
            g<<"1\n";
        }else{
        g<<imp<<"\n";
        }
    }
    delete []a;
    return 0;
}
