#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,t;
int gcd(int a , int b){
int r=a%b;
while (r)
{
    a=b;
    b=r;
    r=a%b;
}
return b;
}
int main()
{
    fin>>t;
    while ( t-- )
    {
    fin>>a>>b;
    fout<<gcd(a,b)<<endl;
    }
}
