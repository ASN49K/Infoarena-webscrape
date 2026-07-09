#include <iostream>
#include <fstream>
using namespace std;
int n,i,a,b;

int gcd(int a, int b){
if(!b)return a;
return gcd(b,a%b);
}

int main()
{   ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++){
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
}
