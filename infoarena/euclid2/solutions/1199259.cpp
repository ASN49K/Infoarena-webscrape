#include <fstream>

using namespace std;

/*function gcd(a, b)
    while b ≠ 0
       t := b
       b := a mod b
       a := t
    return a*/

int gcd(int a, int b)
{
        while(b!=0) {
                int t=b;
                b=a%b;
                a=t;
        }
        return a;
}

int main()
{
        int t, a, b;
        ifstream f("euclid2.in");
        ofstream g("euclid2.out");
        f >> t;
        for (int i = 0; i < t; i++) {
                f >> a >> b;
                g << gcd(a,b) << "\n";
        }
        return 0;
}
