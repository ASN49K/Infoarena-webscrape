#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");

#define ull long int
#define mod 666013


int main()
{
    int n,xorr,t,v;

    in>>t;
    while(t--){
        in>>n;
        xorr    =0;
        for(int i = 0 ; i < n ; i++){
         in>>v;
         xorr ^=v;
        }
        if(xorr>0)
            out<<"DA\n";
        else
            out<<"NU\n";
    }

    return 0;
}
