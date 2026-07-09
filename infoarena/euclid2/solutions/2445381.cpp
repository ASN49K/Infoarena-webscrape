#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b;
int n;
int main()
{
    f>>n;
    while(n!=0){
        f>>a>>b;
        while(b!=0){
            long long c = b;
            b = a%b;
            a = c;
        }
        g<<a<<'\n';
        n--;
    }
}
