//
//  Euclid.cpp
//  InfoArena
//
//  Created by Tim Palade on 9/10/18.
//  Copyright © 2018 Tim Palade. All rights reserved.
//

//#include "Euclid.hpp"
//#include <iostream>

#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    
    f >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        int b;
        f >> a >> b;
        
        g << gcd(a, b) << endl;
    }
    
    f.close();
    g.close();
    
    return 0;
}

