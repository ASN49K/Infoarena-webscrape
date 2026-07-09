#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int a,b,r,t;
int main()
{
     fin>>a>>b;
     r=a%b;
     while(r)
     {
       a=b;
       b=r;
       r=a%b;
     }
    if (b==1) b = 0;
     fout<<b<<'\n';
   return 0;
}
