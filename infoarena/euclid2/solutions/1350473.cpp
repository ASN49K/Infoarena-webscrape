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
    int i,a,b,r;
    for(i=1;i<=t;i++){
        f>>a>>b;
        while(b>0){
            r = a%b;
            a = b;
            b = r;
        }
        cout<<a<<"\n";
    }
    return 0;
}
