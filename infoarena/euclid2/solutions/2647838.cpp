#include<fstream>
#include<iostream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int cnt = 0;
    int a = 0, b = 0;
    f >> cnt;
    for(int i = 0 ; i < cnt; i++)
    {
        f>>a;
        f>>b;

        int gcd_nr = gcd(a,b);

        g << gcd_nr << endl;
    }
}
