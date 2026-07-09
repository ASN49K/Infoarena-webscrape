//
//  main.cpp
//  CMMDC
//
//  Created by Alexandru Chiurtu on 26/01/16.
//  Copyright © 2016 Alexandru Chiurtu. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a,b,t,cmmdc;
    
    ifstream in("euclid2.in.in");
    ofstream out("euclid2.in.out");
    
    in >> t;
    
    for(int i = 0; i < t; i++) {
     
        in >> a >> b;
        
        cmmdc = 0;
        
        if (a < b) {
        
            int j = a;
            
            while (j != 0 && cmmdc !=1) {
                if (a % j == 0 && b % j == 0) {
                    
                    out << j << endl;
                    cmmdc = 1;
                }
                j--;
            }
        } else {
            
            int j = b;
            
            while (j != 0 && cmmdc !=1) {
                if (a % j == 0 && b % j == 0) {
                    
                    out << j << endl;
                    cmmdc = 1;
                }
                j--;
            }
        }
    }
    
    
    return 0;
}
