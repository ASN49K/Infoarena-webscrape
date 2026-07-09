#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int a,b,n;
    f>>n;
    while(n){
        f>>a>>b;
        g<< gcd(a,b)<<'\n';
        n--;
    }
    return 0;
}
