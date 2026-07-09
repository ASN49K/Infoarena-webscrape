//
//  alg_lui_euclid.cpp
//  probleme
//
//  Created by Mihnea Buzoiu on 6/3/21.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int f(int a, int b){
    if (b == 0)
        return a;
    
    return f(b, a%b);
}

int main() {
    
    freopen("euclid2.in", "r", "stdin");
    freopen("euclid2.out", "w", "stdout");
    
    int t, a, b;
    cin >> t;
    
    for (int i=0; i<t; i++){
        cin >> a >> b;
        cout << f(a, b) << "\n";
    }
    
    return 0;
}
