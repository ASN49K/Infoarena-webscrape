#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int A,B;

int main(int argc, char** argv){

    ifstream in; in.open("euclid2.in");
    ofstream out; out.open("euclid2.out");
    int T; in >> T;
    for (int i=0; i<T; i++){
        in>>A>>B;
        out<<gcd(A,B)<<endl;
    }
}
