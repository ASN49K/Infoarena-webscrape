//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
long long euclid(long long a,long long b){
    long long r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    long long n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<euclid(a,b)<<"\n";
    }
    return 0;
}
