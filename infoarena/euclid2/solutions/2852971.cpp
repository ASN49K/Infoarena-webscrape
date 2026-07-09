#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a,long long b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    long long n;
    long long a,b;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    return 0;
}
