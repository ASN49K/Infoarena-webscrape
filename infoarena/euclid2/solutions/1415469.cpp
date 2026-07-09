#include <iostream>
#include <fstream>
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{

    int t,a,b;
    ifstream f ("euclid2.in");
    f>>t;
    ofstream g ("euclid2.out");
    for(int i =1;i<=t;i++){
        f>>a>>b;
        g<<gcd(a,b)<<"\n";
    }
    g.close();
    f.close();
    return 0;
    }

