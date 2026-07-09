#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");
int n,M,K;
int CMMDC(int a,int b)
{
    if(a==b)
        return a;
    else
    {
        if(a>b)
            return (a-b,b);
        else
            return (a,b-a);
    }
}
int main(){
f>>n;
for(int i=0;i<n);
{
    f>>M;
    f>>K;
    o<<CMMDC(M,K)<<"\n";

}
return 0;
}
