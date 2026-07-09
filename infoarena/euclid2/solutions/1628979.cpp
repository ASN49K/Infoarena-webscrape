#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n,a,b,i,r;
    fin>>n;
for(i=1;i<=n;i++)
        {
fin>>a>>b;
while(a%b!=0)
{
r=b;
b=a%b;
a=r;
}
fout<<b<<'\n';
}
    return 0;
}
