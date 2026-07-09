#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a, b, t;

int gcd(int a, int b){
    if(!b)return a;
        else return gcd(b,a%b);
}

int main()
{
    in>>t;

    for(; t; --t)
    {
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }
    return 0;
}
