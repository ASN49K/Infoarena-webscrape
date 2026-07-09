#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a,long long b){
    if(b==0)
        return a;
    if(b>a)
        return gcd(b,a);
    else
        return gcd(b,a%b);
}
int main()
{
    long long n;
    long long a,b;
    fin>>n;
    while(n > 0){
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
        n--;
    }
    return 0;
}
