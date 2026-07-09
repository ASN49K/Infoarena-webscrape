#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int main()
{
    long t;
    unsigned long long a,b,rest;

    in>>t;
    while(t>0){
        in>>a>>b;

        //algoritmul lui euclid
        while(b){
            rest=a%b;
            a=b;
            b=rest;
        }
        out<<a<<'\n';
        t--;
    }

    return 0;
}
