#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b){
    cout<< a<<" "<<b<<'\n';
    if(b==0)
        return a;
    if(b>a)
        return gcd(b,a);
    else
        return gcd(b,a%b);
}
int main()
{
    int n;
    int a,b;
    fin>>n;
    while(n > 0){
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
        n--;
    }
    return 0;
}
