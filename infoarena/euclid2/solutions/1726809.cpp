#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

long int GCD_simple(long int a, long int b){
    long int remainder = b%a;
    while (remainder != 0){
        b = a;
        a = remainder;
        remainder = b%a;
    }
    return a;
}

long int GCD_scaderi(long int a, long int b){

//    cout<<"La inceput "<<a<<" "<<b<<endl;
    int d = 0;
    long int d_pow_2 = 1;
    while ((a % 2 ==0) && (b % 2 == 0)){
        a = a>>1;
        b = b>>1;
        d++;
        d_pow_2=d_pow_2<<1;
//        cout<<a<<" "<<b<<endl;
    }

    while (a != b){
        if (a%2 == 0) { a = a>>1;}
        else if( b%2 ==0) {b = b>>1;}
        else if (a > b) { a = (a-b)>>1;}
        else { b = (b-a)>>1;}

//        cout<<a<<" "<<b<<endl;
    }

    return a * d_pow_2;
}

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

        a = GCD_scaderi(a,b);
        out<<a<<endl;
    }
}
