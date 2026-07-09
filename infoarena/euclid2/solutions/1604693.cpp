#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    f>>T;
    for(int i=0;i<T;i++){
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    return 0;
}
