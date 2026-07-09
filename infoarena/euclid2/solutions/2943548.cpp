//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
long long cmmdc(long long a,long long b){
    long long r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main() {
    long long n;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a>>b;
        cout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
