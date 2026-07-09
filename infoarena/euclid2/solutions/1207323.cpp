#include <iostream>
#include <fstream>
using namespace std;
int n,a,b;

int gcd(int a, int b){
if(!b)return a;
return gcd(b,a%b);
}

int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(;n;n--){
        f>>a>>b;
        g<<gcd(a,b)<<'/n';
    }
    f.close();
    g.close();
    return 0;
}
