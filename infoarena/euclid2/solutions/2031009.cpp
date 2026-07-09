//
//  main.cpp
//  Euclid
//
//  Created by Albastroiu Radu on 9/28/17.
//  Copyright © 2017 Radu Albastroiu. All rights reserved.
//

#include <iostream>

int euclid(int x, int y)
{
    if(!y)
        return x;
    
    return euclid(y, x % y);
}

int T, A, B;

int main() {

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", euclid(A, B));
    }
    
    return 0;
}
