#include <iostream>
#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,t,r,n;
int gcd(int a , int b){
    r=a%b;
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
    fin>>n;
    for (t=0;t<n;t++)
    {
    fin>>a>>b;
    fout<<gcd(a,b)<<endl;
    }
}
