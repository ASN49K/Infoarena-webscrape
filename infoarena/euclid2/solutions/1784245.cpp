#include <iostream>
#include <fstream>
using namespace std;

int cmd(int a, int b){
    if (!b) return a;
    else return cmd(b, a%b);
}

int main()
{
    ifstream citire("euclid2.in");
    ofstream scriere ("euclid2.out");
    int t, a, b;
    citire>>t;
    for(; t; t--){
        citire>>a>>b;
        scriere<<cmd(a,b)<<endl;
    }
    return 0;
}
