#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("an.in");
ofstream fout("an.out");
int main()
{int n,i,a,i1,s=1;
fin>>a;
for(i=1;i<=1000000000;i++)
   {i1=i;
    {while(i1)
   {s=s*i; i1--;}
   if(s%a==0) {fout<<i; break;}}
   s=1}
    return 0;
}
