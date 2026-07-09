#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream citire("euclid2.in");
    ofstream scriere ("euclid2.out");
    int t, a, b, r;
    citire>>t;
    for(; t; t--){
        citire>>a>>b;
        do{
            r=a%b;
            a=b;
            b=r;
        }while(r);
        scriere<<a<<endl;
    }
    return 0;
}
