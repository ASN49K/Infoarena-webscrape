#include<fstream>
#include<iostream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,r,i;
f>>t;
for(i=1;i<=t;i++)
{
    f>>a>>b;
    r=a%b;
    a=b;
    b=r;
    g<<a<<endl;

}
return 0;
}
