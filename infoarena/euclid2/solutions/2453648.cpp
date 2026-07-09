#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int t;
int gcd (int a , int b){
    int r = 0;
    while (b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    f >> t;
    while (t --){
        int a , b;
        f >> a >> b;
        g << gcd (a , b) << '\n';
    }
    return 0;
}
