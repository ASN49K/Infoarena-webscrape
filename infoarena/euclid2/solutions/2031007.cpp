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

int main() {

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    int n;
    std::cin >> n;
    
    int x,y;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        std::cout << euclid(x, y) << "\n";
    }
    
    return 0;
}
