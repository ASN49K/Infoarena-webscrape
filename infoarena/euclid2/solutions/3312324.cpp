/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
int T;
fin>>T;
 for (int i = 0; i < T; i++) {
        long long a, b;
        fin >> a >> b;
        while(b){
        int r=a%b;
        a=b;
        b=r; }
 
 fout << a<< endl;}


    return 0;
}



