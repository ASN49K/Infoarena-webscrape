#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long T,a,b;

long long gcd(long long a, long long b){
    if(a==b)
        return a;
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    f>>T;
    for(long long i=0;i<T;i++){
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    return 0;
}
