#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,t,d,cmmdc,i,p1,p2;
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
   {
       f>>a>>b;d=2;cmmdc=1;
       while(a>1 && b>1)
       {
           p1=p2=0;
           while(a%d==0){p1++;a/=d;}
           while(b%d==0){p2++;b/=d;}
           if(p1<p2)cmmdc=cmmdc*pow(d,p1);
           else cmmdc=cmmdc*pow(d,p2);
           if(d==2)d++;
           else d+=2;
       }
       cout<<cmmdc<<endl;
   }
}
