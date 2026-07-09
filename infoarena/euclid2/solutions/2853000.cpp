#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    fin >> n;
    for(;n;n--)
    {
        fin >> a >> b;
        fout << gcd(a,b) << endl;
    }
    return 0;
}
