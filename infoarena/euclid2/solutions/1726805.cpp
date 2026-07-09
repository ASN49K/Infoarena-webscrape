#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

    ifstream in; in.open("euclid2.in");
    ofstream out; out.open("euclid2.out");
    int T; in >> T;
    vector<pair<long int, long int> > input_data;
    for (int i=0; i<T; i++){
        long int t1,a,b; in>>a>>t1;
        if (a > t1){
            b = a;
            a = t1;
        } else {
            b = t1;
        }

        cout<<"A:"<<a<<"--- B:"<<b<<endl;

        // get GCD
        long int GCD = 1;
        for (long int j=2; j<=a;j++){
            if (( a%j == 0) && ( b%j == 0)){
                GCD *=j; // update GCD
                a/=j; // update a
                b/=j; // update j
                j = 2; // reset j
            }
        }
        out<<GCD<<endl;
    }
}
