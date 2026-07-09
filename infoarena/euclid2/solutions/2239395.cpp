//
//  Euclid.cpp
//  InfoArena
//
//  Created by Tim Palade on 9/10/18.
//  Copyright © 2018 Tim Palade. All rights reserved.
//

//#include "Euclid.hpp"
//#include <iostream>

#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
    
    if (b == 0) {
        return a;
    }
    else if (a == b) {
        return a;
    }
    
    int e = b;
    int r = -1;
    if (a > b) {
        r = a % b;
    }
    else {
        r = b % a;
        e = a;
    }
    
    return gcd(e, r);
}

int T, A, B;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    
    return 0;
}

