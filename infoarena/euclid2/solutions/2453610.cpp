//
//  main.cpp
//  euclid2
//
//  Created by Danut Avadanei on 04/09/2019.
//  Copyright © 2019 ziende. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    
    int T, a, b, r = 0;
    
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        fin >> a >> b;
        
        if (a == b) {
            fout << a << "\n";
            continue;
        }
        
        while (b != 0) {
            r = b;
            b = a % b;
            a = r;
        }
        
        fout << a << "\n";
    }
    
    return 0;
}
