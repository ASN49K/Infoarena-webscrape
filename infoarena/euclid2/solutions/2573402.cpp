#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ifstream out("euclid2.out");

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++){
        in>>a>>b;
        out<<gcd(a,b)<<" ";
    }

}
