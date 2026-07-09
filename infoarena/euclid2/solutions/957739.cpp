#include<iostream>
#include<fstream>
using namespace std;
int main()
{int t,a,b,i,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
cin>>t;
for(i=1;i<=t;i++)
{cin>>a>>b;
while(a%b!=0)
{r=a%b;
a=b;
b=r;
}
g<<b;
}





}
