/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
    int T, a, b;
    int minim;
    
    int cmmdc;
    
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        fin >> a;
        fin >> b;

        // int minim = (a < b) ? a : b;
        
        if (a < b) {
            minim = a;
        } else {
            minim = b;
        }
        
        // in puncutl asta avem minim = min(a, b)
        
        cmmdc = 1;
        
        
        // incercarea naiva iterativa
        // for (int j = 2; j <= minim; j++) {
            
        //     // testam a si b daca sunt ambele divizibile cu j
        //     if ((a % j == 0) && (b % j == 0)) {
                
        //         // daca da, atunci asignam variabilei cmmdc valoare lui j
        //         cmmdc = j;
        //     }
        // }
        
        
        // incercarea prin scadere repetata
        int c;
        while (a != b) {
            while (a > b) {
                c = a - b;
                a = c;
            }
            while (b > a) {
                c = b - a;
                b = c;
            }
        }
        
        // aici avem in variabila cmmdc rezultatul final
        // scriem rezultatul in fisierul de output
        
        cmmdc = c;        
        
        fout << cmmdc << endl;
    }

    return 0;
}
