#include <iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,i,a,b,r;
fin>>t;
for(i=1;i<=t;i++)
    {fin>>a>>b;
    r=a%b;
    while(r!=0)
 {
     a=b;
     b=r;
     r=a%b;
 }
 fout<<b<<endl;
    }
    return 0;
    }
