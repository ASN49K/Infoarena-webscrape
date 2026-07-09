#include <iostream>
#include <fstream>

using namespace std;

int gcd(int,int);

int main()
{   int a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n){
        n--;
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}

int gcd(int a,int b){
    int r;
    while(b!=0){
        r= b;
        b=a%b;
        a=r;
    }
    return a;
}
