#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,t;
int main()
{
  fin>>t;
  for (int i=1;i<=t;i++)
   {
     fin>>a>>b;
     r=a%b;
     while(r)
     {
       a=b;
       b=r;
       r=a%b;
     }
     fout<<b<<'\n';
   }
   return 0;
}
