#include<iostream>
#include<fstream>
using namespace std;
int main ()
{long long n,a,i,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
cin>>n;
for(i=1;i<=n;i++)
    {cin>>a>>b;
    while(a!=b)
    {if(a>b)
    a=a-b;
    else
        b=b-a;}
    cout<<a<<"\n";}
}
