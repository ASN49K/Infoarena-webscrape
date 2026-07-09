/* 
 * File:   JoculNIM.cpp
 * Author: slycer
 *
 * Created on December 25, 2011, 4:13 PM
 */

#include <cstdlib>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream input("nim.in");
    ofstream output ("nim.out");
    
    int n; 
    input >> n; 
    for ( int i=0; i<n; i++){
        int k; 
        input >> k; 
        int aux = 0; 
        for ( int j=0; j<k; j++){
            int c; 
            input >> c; 
            aux = aux ^ c;
        }
        if ( aux == 0 ){
            output << "NU" << "\n";
        } else {
            output << "DA" << "\n";
        }
    }
    
    return 0;
}

