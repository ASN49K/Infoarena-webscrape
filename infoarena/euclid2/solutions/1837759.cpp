#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b){
    int r=a%b;
    if(r==0)return b;
    else return gcd(b,r);
}
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int a,b;
    int n;
    f>>n;
    while(n){
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
        n--;
    }
    return 0;
}
