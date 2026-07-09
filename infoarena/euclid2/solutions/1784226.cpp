#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream citire("euclid2.in");
    ofstream scriere ("euclid2.out");
    int t;
    citire>>t;
    for(int i=1; i<=t; i++){
        int a=0, b=0, r=0;
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
