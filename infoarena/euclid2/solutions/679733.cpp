#include <iostream>
#include <fstream>
using namespace std;
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,r,i;
fin>>t;
for(i=1;i<=t;i++)
{
fin>>a;
fin>>b;
while(b!=0)
{
r=a%b;
a=b;
b=r;
}
fout<<a<<endl;
}

return 0;
}
