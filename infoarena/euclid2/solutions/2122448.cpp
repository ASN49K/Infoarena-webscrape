#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long a,b,r;
int T;
long long cmmmdc(long long a,long long b)
{
    while(b){
    r=a%b; a=b; b=r;
    }
    return a;
}
int main()
{
    in>>T;
    for(int i=1;i<=T;i++) in>>a>>b,out<<cmmmdc(a,b)<<"\n";
    return 0;
}
